# Описание грамматики.

EPS -> ""<br/>
<br/>
S -> VAR BLOCK<br/>
<br/>
VAR -> "var"<br/>
<br/>
BLOCK -> V<br/>
BLOCK -> V BLOCK<br/>
BLOCK -> EPS<br/>
<br/>
V -> NAME COLON TYPE SEMICOLON<br/>
V -> NAME COMMA V<br/>
<br/>
NAME -> LETTER NAME'<br/>
NAME -> EPS<br/>
NAME' -> LETTER NAME'<br/>
NAME' -> DIGIT NAME'<br/>
<br/>
TYPE -> "integer"<br/>
TYPE -> "real"<br/>
TYPE -> "boolean"<br/>
TYPE -> "char"<br/>
<br/>
DIGIT -> "0"<br/>
DIGIT -> "1"<br/>
DIGIT -> "2"<br/>
DIGIT -> "3"<br/>
DIGIT -> "4"<br/>
DIGIT -> "5"<br/>
DIGIT -> "6"<br/>
DIGIT -> "7"<br/>
DIGIT -> "8"<br/>
DIGIT -> "9"<br/>
<br/>
LETTER -> "a"<br/>
LETTER -> "b"<br/>
LETTER -> "c"<br/>
LETTER -> "d"<br/>
LETTER -> "e"<br/>
LETTER -> "f"<br/>
LETTER -> "g"<br/>
<br/>
LETTER -> "A"<br/>
LETTER -> "B"<br/>
LETTER -> "C"<br/>
LETTER -> "D"<br/>
LETTER -> "E"<br/>
LETTER -> "F"<br/>
LETTER -> "G"<br/>