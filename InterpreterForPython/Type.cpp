#include "Type.h"

Type::Type()
{
	_isTemp = false;
}

void Type::setTemp(const bool value)
{
	_isTemp = value;
}

int Type::getTemp() const
{
	return _isTemp;
}
