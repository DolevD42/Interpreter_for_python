#include "Void.h"

Void::Void(bool temp) : Type()
{
	_isTemp = temp;
}

bool Void::isPrintable() const
{
	return false;
}

std::string Void::toString() const
{
	return "";
}
