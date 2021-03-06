;; Example executable program

#.`(defsystem :hello-world-example
     ;; :build-operation program-op ; this would cause the executable output in same directory :-/
     :entry-point "hello:entry-point"
     :depends-on (:uiop)
     :components ((:file "hello"))
     #+mkcl
     ,@`(;;:prefix-lisp-object-files (,(namestring (truename (translate-logical-pathname #P"SYS:cmp.a"))))
         :extra-build-args ;;,(or #-windows '(:use-mkcl-shared-libraries nil :use-external-shared-libraries nil))
         (:all-static-program t)
         :class program-system
         :epilogue-code (progn
                          (setq uiop/image:*image-dumped-p* :executable)
                          (setq uiop/image:*lisp-interaction* nil)
                          (uiop/image:restore-image :entry-point (read-from-string "hello:entry-point")))))
