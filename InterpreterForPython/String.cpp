#include "String.h"

String::String(std::string object, bool temp) : Sequence()
{
	_value = object;
	_isTemp = temp;
}

bool String::isPrintable() const
{
	return true;
}

std::string String::toString() const
{
	if (_value.find((char)39) != std::string::npos)
	{
		return (char)34 + _value + (char)34;
	}
	return "'" + _value + "'";
}
