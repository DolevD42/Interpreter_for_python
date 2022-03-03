#include "TypeException.h"

TypeException::TypeException(std::string type, std::string func)
{
	_type = type;
	_funcName = func;
}

const char* TypeException::what() const noexcept
{
	std::string msg = "TypeError : object of type '" + _type + "' has no " + _funcName+"()";
	const char* c = msg.c_str();
	printf("%s", c);
	return ""; //for some reason, when I try to return the char* or the string, it doesn't print good
}
