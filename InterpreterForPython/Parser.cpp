#include "Parser.h"
#include <iostream>


std::unordered_map<std::string, Type*> Parser::_variables = {};

Type* Parser::parseString(std::string str)
{
	if (str[0] == ' ' || str[0] == '	')
	{
		throw(IndentationException());				
	}
	if (str.length() > 0)
	{
		Helper::rtrim(str);
		Type* Object = getType(str);
		 if (Object != NULL)
		{
			return Object;
		}
		else if(makeAssignment(str))
		{
			return new Void(true);
		}
		else if (isLegalVarName(str))
		{
			Type* Object = getVariableValue(str);
			if (Object != NULL)
			{
				return Object;
			}
			else
			{
				throw(NameErrorException(str));
			}
		}
		else if (str.substr(0, 5) == "type(" && str[str.length() - 1] == ')')
		 {
			 str.erase(0, 5);
			 str.pop_back();
			 Type* object = parseString(str);
			 if ( object!=NULL)
			 {
				 if (object->isPrintable())
				 {
					 if (object->toString()[0] == '[' && object->toString()[object->toString().length() - 1] == ']')
					 {
						 std::cout << "<type 'list'>" << std::endl;
						 return new Void(true);
					 }
					 if ((object->toString()[0] == '"' && object->toString()[object->toString().length() - 1] == '"') || (object->toString()[0] == (char)39 && object->toString()[object->toString().length() - 1] == (char)39))
					 {
						 std::cout << "<type 'str'>" << std::endl;
						 return new Void(true);
					 }
					 if (object->toString() == "True" || object->toString() == "False")
					 {
						 std::cout << "<type 'bool'>" << std::endl;
						 return new Void(true);
					 }
					 std::cout << "<type 'int'>" << std::endl;
					 return new Void(true);
				 }
				 else
				 {
					 throw(SyntaxException());
				 }
			 }
			 else
			 {
				 throw(SyntaxException());
			 }
		 }

	return NULL;
}


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

void Parser::cleanMemory()
{
	for (auto itr = _variables.begin(); itr != _variables.end(); itr++)
	{
		if (itr->second)
		{
			if (itr->second->toString()[0] == '[' && itr->second->toString()[itr->second->toString().length() - 1] == ']')
			{
				for (auto secItr = _variables.begin(); secItr != _variables.end(); secItr++)
				{
					if (itr != secItr && secItr->second == itr->second)
					{
						secItr->second = NULL;
					}
				}
			}
		}
	}
	for (auto itr = _variables.begin(); itr != _variables.end(); itr++)
	{
		if (itr->second)
		{
			delete itr->second;
		}
	}
	_variables.clear();
}


bool Parser::isLegalVarName(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && Helper::isDigit(str[0]))
		{
			return false;
		}
		if (!Helper::isDigit(str[i]) && !Helper::isLetter(str[i]) && !Helper::isUnderscore(str[i]))
		{
			return false;
		}
	}
	if (str == "False" || str == "True")
	{
		return false;
	}
	return true;
}

bool Parser::makeAssignment(std::string str)
{
	if (str.find("=") == std::string::npos)
	{
		return false;
	}
	int index = str.find("=");
	std::string name = str.substr(0, index);
	std::string value = str.substr(index + 1, str.length() - index - 1);
	Helper::trim(name);
	Helper::trim(value);
	if (!isLegalVarName(name))
	{
		throw(SyntaxException());
	}
	Type* object = getType(value);
	if (object == NULL)
	{
		if (isLegalVarName(value))
		{
			Type* object = getVariableValue(value);
			if (object != NULL)
			{
				object->setTemp(false);
				std::string objectString = object->toString();
				if (objectString[0] == '[')
				{
					_variables[name] = object;
				}
				else
				{
					Type* newObject = getType(objectString);
					_variables[name] = newObject;
				}
				
			}
			else
			{
				throw(NameErrorException(value));
			}
		}
		else
		{
			throw(SyntaxException());
		}
	}
	else
	{
		object->setTemp(false);
		_variables[name] = object;
	}
	return true;

}

Type* Parser::getVariableValue(std::string str)
{
	if (_variables.find(str) == _variables.end())
	{
		return NULL;
	}
	for (auto itr = _variables.begin(); itr != _variables.end(); itr++)
	{
		if (itr->first == str)
		{
			return itr->second;
		}
	}
}


