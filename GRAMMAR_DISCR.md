# Описание грамматики.

EPS -> ""

S -> VAR BLOCK

VAR -> "var"

BLOCK -> V
BLOCK -> V BLOCK
BLOCK -> EPS

V -> NAME COLON TYPE SEMICOLON
V -> NAME COMMA V

NAME -> LETTER NAME'
NAME -> EPS
NAME' -> LETTER NAME'
NAME' -> DIGIT NAME'

TYPE -> "integer"
TYPE -> "real"
TYPE -> "boolean"
TYPE -> "char"

DIGIT -> "0"
DIGIT -> "1"
DIGIT -> "2"
DIGIT -> "3"
DIGIT -> "4"
DIGIT -> "5"
DIGIT -> "6"
DIGIT -> "7"
DIGIT -> "8"
DIGIT -> "9"

LETTER -> "a"
LETTER -> "b"
LETTER -> "c"
LETTER -> "d"
LETTER -> "e"
LETTER -> "f"
LETTER -> "g"

LETTER -> "A"
LETTER -> "B"
LETTER -> "C"
LETTER -> "D"
LETTER -> "E"
LETTER -> "F"
LETTER -> "G"