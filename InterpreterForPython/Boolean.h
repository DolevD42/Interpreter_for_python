#pragma once
#include "Type.h"
class Boolean :
    public Type
{
public:
	Boolean(bool object, bool temp);
	virtual bool isPrintable() const;
	virtual std::string toString() const;
private:
	bool _value;
};