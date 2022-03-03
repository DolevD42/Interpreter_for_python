#pragma once
#include "IndentationException.h"
#include "SyntaxException.h"
#include "NameErrorException.h"
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
};