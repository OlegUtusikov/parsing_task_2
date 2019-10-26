#pragma once

#include <string>

class Token {
public:
	enum class TYPE {
		DIGIT,
		LETTER,
		NAME,
		TYPE,
		COLLON,
		COMMA,
		SEMICOLLON,
		VAR,
		END
	};
	
private:
	TYPE m_type;
	std::string m_value;
};