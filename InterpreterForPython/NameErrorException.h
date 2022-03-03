#pragma once
#include "InterpreterException.h"
class NameErrorException :
    public InterpreterException
{
public:
    NameErrorException(std::string name);
    virtual const char* what() const noexcept;
private:
    std::string _name;
};

