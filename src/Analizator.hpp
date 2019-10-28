#pragma once

#include <string>
#include "Tokenizer.hpp"
#include "Tree.hpp"

class Analizator
{
public:
	Analizator() : tr("")
	{}

	Node parse(std::string const& s);
private:
	using TYPE = Token::TYPE;
	Tokenizer tr;
	// recurse parse methods
	void print_error() const;
	void print_info(std::string const& s) const;
	Node var();
	Node block();
	Node v();
};