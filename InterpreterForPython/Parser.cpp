#include "Parser.h"
#include <iostream>


Type* Parser::parseString(std::string str)
{
	if (str[0] == ' ' || str[0] == '	')
	{
		throw(IndentationException());				
	}
	if (str.length() > 0)
	{
	}

	return NULL;
}
