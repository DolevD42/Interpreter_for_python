#pragma once
#include "InterpreterException.h"
class TypeException :
    public InterpreterException
{
public:
    TypeException(std::string type, std::string func);
    virtual const char* what() const noexcept;
private:
    std::string _type;
    std::string _funcName;
};

