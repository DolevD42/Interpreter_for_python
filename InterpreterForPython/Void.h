#pragma once
#include "Type.h"
class Void :
    public Type
{
public:
	Void(bool temp);
	virtual bool isPrintable() const;
	virtual std::string toString() const;
};

