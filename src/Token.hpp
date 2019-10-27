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
		END,
		EPS
	};

	Token(): m_value("empty"), m_type(TYPE::EPS)
	{
	}

	Token(std::string const& value, TYPE type): m_value(value), m_type(type)
	{}

	std::string value() const
	{
		return m_value;
	}

	TYPE type() const
	{
		return m_type;
	}

	int type_int() const
	{
		return static_cast<int>(m_type);
	}

	std::string type_str() const
	{
		switch (m_type)
		{
		case TYPE::DIGIT:
			return "DIGIT";
		case TYPE::LETTER:
			return "LETTER";
		case TYPE::NAME:
			return "NAME";
		case TYPE::TYPE:
			return "TYPE";
		case TYPE::COLLON:
			return "COLLON";
		case TYPE::COMMA:
			return "COMMA";
		case TYPE::SEMICOLLON:
			return "SEMICOLLON";
		case TYPE::VAR:
			return "VAR";
		case TYPE::END:
			return "END";
		case TYPE::EPS:
			return "EPS";
		default:
			return "fuck";
			break;
		}
	}

private:
	TYPE m_type;
	std::string m_value;
};