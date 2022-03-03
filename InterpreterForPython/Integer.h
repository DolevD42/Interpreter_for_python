#pragma once
#include "Type.h"
class Integer :
    public Type
{
public:
	Integer(int object, bool temp);
	virtual bool isPrintable() const;
	virtual std::string toString() const;
private:
	int _value;
};

