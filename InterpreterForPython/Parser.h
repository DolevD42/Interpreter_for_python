#pragma once
#include "IndentationException.h"
#include "SyntaxException.h"
#include "NameErrorException.h"
#include "TypeException.h"
#include "Type.h"
#include "String.h"
#include "Void.h"
#include "Integer.h"
#include "Boolean.h"
#include "List.h"
#include "Helper.h"
#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>


class Parser
{
public:
    static Type* parseString(std::string str);
    static Type* getType(std::string str);
    static void cleanMemory();
private:
    static bool isLegalVarName(std::string str);
    static bool makeAssignment(std::string str);
    static Type* getVariableValue(std::string str);
    static std::unordered_map<std::string, Type*> _variables;
};