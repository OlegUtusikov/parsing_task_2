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
	
	Token()
	{
		m_type = TYPE::END;
		m_value = "";
	}

	Token(std::string const& value, TYPE type): m_value(value), m_type(type)
	{}

private:
	TYPE m_type;
	std::string m_value;
};