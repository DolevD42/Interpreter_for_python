#pragma once
#include "IndentationException.h"
#include "Type.h"
#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>


class Parser
{
public:
    static Type* parseString(std::string str);
};