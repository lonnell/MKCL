/*
 * Copyright (c) 2003-2011 Hewlett-Packard Development Company, L.P.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "../all_aligned_atomic_load_store.h"

/* Real X86 implementations appear                                      */
/* to enforce ordering between memory operations, EXCEPT that a later   */
/* read can pass earlier writes, presumably due to the visible          */
/* presence of store buffers.                                           */
/* We ignore the fact that the official specs                           */
/* seem to be much weaker (and arguably too weak to be usable).         */

#include "../ordered_except_wr.h"

#ifdef MK_AO_ASM_X64_AVAILABLE
# include "../test_and_set_t_is_char.h"
#else
# include "../test_and_set_t_is_ao_t.h"
#endif

#include <windows.h>
        /* Seems like over-kill, but that's what MSDN recommends.       */
        /* And apparently winbase.h is not always self-contained.       */

/* Assume _MSC_VER >= 1400 */
#include <intrin.h>

#pragma intrinsic (_InterlockedExchangeAdd)
#pragma intrinsic (_InterlockedCompareExchange64)

#ifndef MK_AO_PREFER_GENERALIZED

# pragma intrinsic (_InterlockedIncrement64)
# pragma intrinsic (_InterlockedDecrement64)
# pragma intrinsic (_InterlockedExchangeAdd64)

MK_AO_INLINE MK_AO_t
MK_AO_fetch_and_add_full (volatile MK_AO_t *p, MK_AO_t incr)
{
  return _InterlockedExchangeAdd64((LONGLONG volatile *)p, (LONGLONG)incr);
}
#define MK_AO_HAVE_fetch_and_add_full

MK_AO_INLINE MK_AO_t
MK_AO_fetch_and_add1_full (volatile MK_AO_t *p)
{
  return _InterlockedIncrement64((LONGLONG volatile *)p) - 1;
}
#define MK_AO_HAVE_fetch_and_add1_full

MK_AO_INLINE MK_AO_t
MK_AO_fetch_and_sub1_full (volatile MK_AO_t *p)
{
  return _InterlockedDecrement64((LONGLONG volatile *)p) + 1;
}
#define MK_AO_HAVE_fetch_and_sub1_full
#endif /* !MK_AO_PREFER_GENERALIZED */

MK_AO_INLINE MK_AO_t
MK_AO_fetch_compare_and_swap_full(volatile MK_AO_t *addr, MK_AO_t old_val,
                               MK_AO_t new_val)
{
  return (MK_AO_t)_InterlockedCompareExchange64((LONGLONG volatile *)addr,
                                        (LONGLONG)new_val, (LONGLONG)old_val);
}
#define MK_AO_HAVE_fetch_compare_and_swap_full

MK_AO_INLINE unsigned int
MK_AO_int_fetch_and_add_full(volatile unsigned int *p, unsigned int incr)
{
  return _InterlockedExchangeAdd((LONG volatile *)p, incr);
}
#define MK_AO_HAVE_int_fetch_and_add_full

#ifdef MK_AO_ASM_X64_AVAILABLE

  MK_AO_INLINE unsigned char
  MK_AO_char_fetch_and_add_full(volatile unsigned char *p, unsigned char incr)
  {
    __asm
    {
      mov al, incr
      mov rbx, p
      lock xadd byte ptr [rbx], al
    }
  }
# define MK_AO_HAVE_char_fetch_and_add_full

  MK_AO_INLINE unsigned short
  MK_AO_short_fetch_and_add_full(volatile unsigned short *p, unsigned short incr)
  {
    __asm
    {
      mov ax, incr
      mov rbx, p
      lock xadd word ptr [rbx], ax
    }
  }
# define MK_AO_HAVE_short_fetch_and_add_full

/* As far as we can tell, the lfence and sfence instructions are not    */
/* currently needed or useful for cached memory accesses.               */

  MK_AO_INLINE void
  MK_AO_nop_full(void)
  {
    /* Note: "mfence" (SSE2) is supported on all x86_64/amd64 chips.    */
    __asm { mfence }
  }
# define MK_AO_HAVE_nop_full

  MK_AO_INLINE MK_AO_TS_VAL_t
  MK_AO_test_and_set_full(volatile MK_AO_TS_t *addr)
  {
    __asm
    {
        mov     rax,MK_AO_TS_SET           ;
        mov     rbx,addr                ;
        xchg    byte ptr [rbx],al       ;
    }
  }
# define MK_AO_HAVE_test_and_set_full

#endif /* MK_AO_ASM_X64_AVAILABLE */

#ifdef MK_AO_CMPXCHG16B_AVAILABLE
/* MK_AO_compare_double_and_swap_double_full needs implementation for Win64.
 * Also see ../gcc/x86.h for partial old Opteron workaround.
 */

# if _MSC_VER >= 1500

#   include "../standard_ao_double_t.h"

#   pragma intrinsic (_InterlockedCompareExchange128)

MK_AO_INLINE int
MK_AO_compare_double_and_swap_double_full(volatile MK_AO_double_t *addr,
                                       MK_AO_t old_val1, MK_AO_t old_val2,
                                       MK_AO_t new_val1, MK_AO_t new_val2)
{
   __int64 comparandResult[2];
   comparandResult[0] = old_val1; /* low */
   comparandResult[1] = old_val2; /* high */
   return _InterlockedCompareExchange128((volatile __int64 *)addr,
                new_val2 /* high */, new_val1 /* low */, comparandResult);
}
#   define MK_AO_HAVE_compare_double_and_swap_double_full

# elif defined(MK_AO_ASM_X64_AVAILABLE)

#   include "../standard_ao_double_t.h"

    /* If there is no intrinsic _InterlockedCompareExchange128 then we  */
    /* need basically what's given below.                               */
MK_AO_INLINE int
MK_AO_compare_double_and_swap_double_full(volatile MK_AO_double_t *addr,
                                       MK_AO_t old_val1, MK_AO_t old_val2,
                                       MK_AO_t new_val1, MK_AO_t new_val2)
{
        __asm
        {
                mov     rdx,QWORD PTR [old_val2]        ;
                mov     rax,QWORD PTR [old_val1]        ;
                mov     rcx,QWORD PTR [new_val2]        ;
                mov     rbx,QWORD PTR [new_val1]        ;
                lock cmpxchg16b [addr]                  ;
                setz    rax                             ;
        }
}
#   define MK_AO_HAVE_compare_double_and_swap_double_full
# endif /* MK_AO_ASM_X64_AVAILABLE && (_MSC_VER < 1500) */

#endif /* MK_AO_CMPXCHG16B_AVAILABLE */
