#include "List.h"

List::List(std::vector<Type*> elements, bool temp) : Sequence()
{
	_isTemp = temp;
	_elements = elements;
}

List::~List()
{
	for (int i = 0; i < _elements.size(); i++)
	{
		delete _elements[i];
	}
	_elements.clear();
}

bool List::isPrintable() const
{
	return true;
}

std::string List::toString() const
{
	std::string returnStr = "[";
	for (int i = 0; i < _elements.size(); i++)
	{
		if (i != 0)
		{
			returnStr += ", ";
		}
		returnStr += _elements[i]->toString();
	}
	returnStr += "]";
	return returnStr;
}
