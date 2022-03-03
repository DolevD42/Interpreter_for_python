#include "Parser.h"
#include <iostream>


Type* Parser::parseString(std::string str)
{
	if (str[0] == ' ' || str[0] == '	')
	{
		throw(IndentationException());				
	}
	if (str.length() > 0)
	{
Type* Parser::getType(std::string str)
{
	Helper::trim(str);
	if (Helper::isInteger(str))
	{
		Integer* object = new Integer(std::stoi(str), true);
		return object;
	}
	if (Helper::isBoolean(str))
	{
		bool boolValue = false;
		if (str[0] == 'T')
		{
			boolValue = true;
		}
		Boolean* object = new Boolean(boolValue, true);
		return object;
	}
	if (Helper::isString(str))
	{
		str.pop_back();
		str.erase(0, 1);
		String* object = new String(str, true);
		return object;
	}
	if (str[0] == '[' && str[str.length()-1] == ']')
	{
		std::vector<Type*> vect;
		int place = -1;
		int lastPlace = -1;
		str.pop_back();
		str.erase(0, 1);
		if (str.length() != 0)
		{
			str += ",";
		}
		lastPlace = str.find(",");
		while (lastPlace!=std::string::npos)
		{
			std::string strObject = str.substr(place + 1, lastPlace - (place + 1));
			Helper::trim(strObject);
			Type* object = getType(strObject);
			if (object == NULL)
			{
				return NULL;
			}
			vect.push_back(object);
			place = lastPlace;
			lastPlace = str.find(",", lastPlace + 1);
		}
		List* objectToCreate = new List(vect, true);
		return objectToCreate;

	}
	return NULL;
}
