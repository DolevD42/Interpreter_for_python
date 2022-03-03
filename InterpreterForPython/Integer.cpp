#include "Integer.h"

Integer::Integer(int object, bool temp) : Type()
{
	_value = object;
	_isTemp = temp;
}

bool Integer::isPrintable() const
{
	return true;
}

std::string Integer::toString() const
{
	return std::to_string(_value);
}
