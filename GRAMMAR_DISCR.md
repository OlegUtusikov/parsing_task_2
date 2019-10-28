S -> VAR BLOCK</br>
BLOCK -> V</br>
BLOCK -> V BLOCK</br>
BLOCK -> EPS</br>
V -> NAME COLON TYPE SEMICOLON</br>
V -> NAME COMMA V</br>
NAME -> LETTER NAME'</br>
NAME' -> EPS</br>
NAME' -> LETTER NAME'</br>
NAME' -> DIGIT NAME'</br>
</br>
/*</br>
	VAR -> "var"</br>
	TYPE -> "integer"</br>
	TYPE -> "real"</br>
	TYPE -> "boolean"</br>
	TYPE -> "char"</br>
	EPS -> ""</br>
	COLON -> ":"</br>
	SEMICOLON -> ";"</br>
	COMMA -> ","</br>
*/</br>
</br>
FIRST(NAME') = {EPS, LETTER, DIGIT}</br>
FIRST(NAME) = {LETTER}</br>
FIRST(V) = {LETTER}</br>
FIRST(BLOCK) = {EPS, LETTER}</br>
FIRST(S) = {VAR}</br>

FOLLOW(NAME') = {}
FOLLOW(NAME) = {}
FOLLOW(V) = {}
FOLLOW(BLOCK) = {}
FOLLOW(S) = {}
