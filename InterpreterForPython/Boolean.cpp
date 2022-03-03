#include "Boolean.h"
Boolean::Boolean(bool object, bool temp) : Type()
{
	_value = object;
	_isTemp = temp;
}

bool Boolean::isPrintable() const
{
	return true;
}

std::string Boolean::toString() const
{
	if (_value)
	{
		return "True";
	}
	else
	{
		return "False";
	}
}
