#pragma once
#include "Sequence.h"
#include <vector>
class List :
    public Sequence
{
public:
	List(std::vector<Type*> elements, bool temp);
	~List();
	virtual bool isPrintable() const;
	virtual std::string toString() const;
private:
	std::vector<Type*> _elements;
};

