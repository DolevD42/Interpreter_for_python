#pragma once
#include "Sequence.h"
class String :
    public Sequence
{
public:
	String(std::string object, bool temp);
	virtual bool isPrintable() const;
	virtual std::string toString() const;
private:
	std::string _value;
};

