#pragma once

#include <string>
#include "Tokenizer.hpp"
#include "Tree.hpp"

class Analizator
{
public:
	Analizator() : tr("")
	{}

	Node* parse(std::string const& s);

private:
	using TYPE = Token::TYPE;
	Tokenizer tr;
	// recurse parse methods

	Node* var();
	Node* block();
	Node* v();
};