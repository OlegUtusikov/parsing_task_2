S -> VAR BLOCK</br>
BLOCK -> V</br>
BLOCK -> V BLOCK</br>
BLOCK -> EPS</br>
V -> NAME COLON TYPE SEMICOLON</br>
V -> NAME COMMA V</br>
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
FIRST(V) = {NAME}</br>
FIRST(BLOCK) = {EPS, NAME}</br>
FIRST(S) = {VAR}</br>
</br>
FOLLOW(V) = {END, NAME}</br>
FOLLOW(BLOCK) = {END}</br>
FOLLOW(S) = {END}</br>
