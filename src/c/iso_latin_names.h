
static char *base_char_names[] = {
"Nul",
"Soh",
"Stx",
"Etx",
"Eot",
"Enq",
"Ack",
"Bel",
"Backspace",
"Tab",
"Newline",
"Vt",
"Page",
"Return",
"So",
"Si",
"Dle",
"Dc1",
"Dc2",
"Dc3",
"Dc4",
"Nak",
"Syn",
"Etb",
"Can",
"Em",
"Sub",
"Esc",
"Fs",
"Gs",
"Rs",
"Us",
"Space",
"EXCLAMATION_MARK",
"QUOTATION_MARK",
"NUMBER_SIGN",
"DOLLAR_SIGN",
"PERCENT_SIGN",
"AMPERSAND",
"APOSTROPHE",
"LEFT_PARENTHESIS",
"RIGHT_PARENTHESIS",
"ASTERISK",
"PLUS_SIGN",
"COMMA",
"HYPHEN-MINUS",
"FULL_STOP",
"SOLIDUS",
"DIGIT_ZERO",
"DIGIT_ONE",
"DIGIT_TWO",
"DIGIT_THREE",
"DIGIT_FOUR",
"DIGIT_FIVE",
"DIGIT_SIX",
"DIGIT_SEVEN",
"DIGIT_EIGHT",
"DIGIT_NINE",
"COLON",
"SEMICOLON",
"LESS-THAN_SIGN",
"EQUALS_SIGN",
"GREATER-THAN_SIGN",
"QUESTION_MARK",
"COMMERCIAL_AT",
"LATIN_CAPITAL_LETTER_A",
"LATIN_CAPITAL_LETTER_B",
"LATIN_CAPITAL_LETTER_C",
"LATIN_CAPITAL_LETTER_D",
"LATIN_CAPITAL_LETTER_E",
"LATIN_CAPITAL_LETTER_F",
"LATIN_CAPITAL_LETTER_G",
"LATIN_CAPITAL_LETTER_H",
"LATIN_CAPITAL_LETTER_I",
"LATIN_CAPITAL_LETTER_J",
"LATIN_CAPITAL_LETTER_K",
"LATIN_CAPITAL_LETTER_L",
"LATIN_CAPITAL_LETTER_M",
"LATIN_CAPITAL_LETTER_N",
"LATIN_CAPITAL_LETTER_O",
"LATIN_CAPITAL_LETTER_P",
"LATIN_CAPITAL_LETTER_Q",
"LATIN_CAPITAL_LETTER_R",
"LATIN_CAPITAL_LETTER_S",
"LATIN_CAPITAL_LETTER_T",
"LATIN_CAPITAL_LETTER_U",
"LATIN_CAPITAL_LETTER_V",
"LATIN_CAPITAL_LETTER_W",
"LATIN_CAPITAL_LETTER_X",
"LATIN_CAPITAL_LETTER_Y",
"LATIN_CAPITAL_LETTER_Z",
"LEFT_SQUARE_BRACKET",
"REVERSE_SOLIDUS",
"RIGHT_SQUARE_BRACKET",
"CIRCUMFLEX_ACCENT",
"LOW_LINE",
"GRAVE_ACCENT",
"LATIN_SMALL_LETTER_A",
"LATIN_SMALL_LETTER_B",
"LATIN_SMALL_LETTER_C",
"LATIN_SMALL_LETTER_D",
"LATIN_SMALL_LETTER_E",
"LATIN_SMALL_LETTER_F",
"LATIN_SMALL_LETTER_G",
"LATIN_SMALL_LETTER_H",
"LATIN_SMALL_LETTER_I",
"LATIN_SMALL_LETTER_J",
"LATIN_SMALL_LETTER_K",
"LATIN_SMALL_LETTER_L",
"LATIN_SMALL_LETTER_M",
"LATIN_SMALL_LETTER_N",
"LATIN_SMALL_LETTER_O",
"LATIN_SMALL_LETTER_P",
"LATIN_SMALL_LETTER_Q",
"LATIN_SMALL_LETTER_R",
"LATIN_SMALL_LETTER_S",
"LATIN_SMALL_LETTER_T",
"LATIN_SMALL_LETTER_U",
"LATIN_SMALL_LETTER_V",
"LATIN_SMALL_LETTER_W",
"LATIN_SMALL_LETTER_X",
"LATIN_SMALL_LETTER_Y",
"LATIN_SMALL_LETTER_Z",
"LEFT_CURLY_BRACKET",
"VERTICAL_LINE",
"RIGHT_CURLY_BRACKET",
"TILDE",
"Rubout",
"U0080",
"U0081",
"U0082",
"U0083",
"U0084",
"U0085",
"U0086",
"U0087",
"U0088",
"U0089",
"U008A",
"U008B",
"U008C",
"U008D",
"U008E",
"U008F",
"U0090",
"U0091",
"U0092",
"U0093",
"U0094",
"U0095",
"U0096",
"U0097",
"U0098",
"U0099",
"U009A",
"U009B",
"U009C",
"U009D",
"U009E",
"U009F",
"NO-BREAK_SPACE",
"INVERTED_EXCLAMATION_MARK",
"CENT_SIGN",
"POUND_SIGN",
"CURRENCY_SIGN",
"YEN_SIGN",
"BROKEN_BAR",
"SECTION_SIGN",
"DIAERESIS",
"COPYRIGHT_SIGN",
"FEMININE_ORDINAL_INDICATOR",
"LEFT-POINTING_DOUBLE_ANGLE_QUOTATION_MARK",
"NOT_SIGN",
"SOFT_HYPHEN",
"REGISTERED_SIGN",
"MACRON",
"DEGREE_SIGN",
"PLUS-MINUS_SIGN",
"SUPERSCRIPT_TWO",
"SUPERSCRIPT_THREE",
"ACUTE_ACCENT",
"MICRO_SIGN",
"PILCROW_SIGN",
"MIDDLE_DOT",
"CEDILLA",
"SUPERSCRIPT_ONE",
"MASCULINE_ORDINAL_INDICATOR",
"RIGHT-POINTING_DOUBLE_ANGLE_QUOTATION_MARK",
"VULGAR_FRACTION_ONE_QUARTER",
"VULGAR_FRACTION_ONE_HALF",
"VULGAR_FRACTION_THREE_QUARTERS",
"INVERTED_QUESTION_MARK",
"LATIN_CAPITAL_LETTER_A_WITH_GRAVE",
"LATIN_CAPITAL_LETTER_A_WITH_ACUTE",
"LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX",
"LATIN_CAPITAL_LETTER_A_WITH_TILDE",
"LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS",
"LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE",
"LATIN_CAPITAL_LETTER_AE",
"LATIN_CAPITAL_LETTER_C_WITH_CEDILLA",
"LATIN_CAPITAL_LETTER_E_WITH_GRAVE",
"LATIN_CAPITAL_LETTER_E_WITH_ACUTE",
"LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX",
"LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS",
"LATIN_CAPITAL_LETTER_I_WITH_GRAVE",
"LATIN_CAPITAL_LETTER_I_WITH_ACUTE",
"LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX",
"LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS",
"LATIN_CAPITAL_LETTER_ETH",
"LATIN_CAPITAL_LETTER_N_WITH_TILDE",
"LATIN_CAPITAL_LETTER_O_WITH_GRAVE",
"LATIN_CAPITAL_LETTER_O_WITH_ACUTE",
"LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX",
"LATIN_CAPITAL_LETTER_O_WITH_TILDE",
"LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS",
"MULTIPLICATION_SIGN",
"LATIN_CAPITAL_LETTER_O_WITH_STROKE",
"LATIN_CAPITAL_LETTER_U_WITH_GRAVE",
"LATIN_CAPITAL_LETTER_U_WITH_ACUTE",
"LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX",
"LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS",
"LATIN_CAPITAL_LETTER_Y_WITH_ACUTE",
"LATIN_CAPITAL_LETTER_THORN",
"LATIN_SMALL_LETTER_SHARP_S",
"LATIN_SMALL_LETTER_A_WITH_GRAVE",
"LATIN_SMALL_LETTER_A_WITH_ACUTE",
"LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX",
"LATIN_SMALL_LETTER_A_WITH_TILDE",
"LATIN_SMALL_LETTER_A_WITH_DIAERESIS",
"LATIN_SMALL_LETTER_A_WITH_RING_ABOVE",
"LATIN_SMALL_LETTER_AE",
"LATIN_SMALL_LETTER_C_WITH_CEDILLA",
"LATIN_SMALL_LETTER_E_WITH_GRAVE",
"LATIN_SMALL_LETTER_E_WITH_ACUTE",
"LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX",
"LATIN_SMALL_LETTER_E_WITH_DIAERESIS",
"LATIN_SMALL_LETTER_I_WITH_GRAVE",
"LATIN_SMALL_LETTER_I_WITH_ACUTE",
"LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX",
"LATIN_SMALL_LETTER_I_WITH_DIAERESIS",
"LATIN_SMALL_LETTER_ETH",
"LATIN_SMALL_LETTER_N_WITH_TILDE",
"LATIN_SMALL_LETTER_O_WITH_GRAVE",
"LATIN_SMALL_LETTER_O_WITH_ACUTE",
"LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX",
"LATIN_SMALL_LETTER_O_WITH_TILDE",
"LATIN_SMALL_LETTER_O_WITH_DIAERESIS",
"DIVISION_SIGN",
"LATIN_SMALL_LETTER_O_WITH_STROKE",
"LATIN_SMALL_LETTER_U_WITH_GRAVE",
"LATIN_SMALL_LETTER_U_WITH_ACUTE",
"LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX",
"LATIN_SMALL_LETTER_U_WITH_DIAERESIS",
"LATIN_SMALL_LETTER_Y_WITH_ACUTE",
"LATIN_SMALL_LETTER_THORN",
"LATIN_SMALL_LETTER_Y_WITH_DIAERESIS",
/* 0 */
};
