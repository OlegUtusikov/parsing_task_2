#pragma once

#include <string>

class Token {
public:
	enum class TYPE {
		VAR,
		BLOCK,
		NAME,
		TYPE,
		COLLON,
		COMMA,
		SEMICOLLON,
		END,
		EPS
	};

	Token(): m_value("empty"), m_type(TYPE::EPS), m_is_term(true)
	{
	}

	Token(std::string const& value, TYPE type): m_value(value), m_type(type), m_is_term(true)
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
		case TYPE::VAR:
			return "VAR";
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
		case TYPE::END:
			return "END";
		case TYPE::EPS:
			return "EPS";
		default:
			return "fuck";
			break;
		}
	}

	bool is_term() const
	{
		return m_is_term;
	}

	void set_term(bool val)
	{
		m_is_term = val;
	}

private:
	TYPE m_type;
	std::string m_value;
	bool m_is_term;
};