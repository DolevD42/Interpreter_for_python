#pragma once
#include "Type.h"
class Sequence :
    public Type
{
public:
	Sequence();
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;
};

