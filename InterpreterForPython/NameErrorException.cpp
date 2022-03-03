#include "NameErrorException.h"

NameErrorException::NameErrorException(std::string name)
{
    _name = name;
}

const char* NameErrorException::what() const noexcept
{
    std::string msg = "NameError : name '" + _name + "' is not defined";
    const char* c = msg.c_str();
    printf("%s", c); 
    return ""; //for some reason, when I try to return the char* or the string, it doesn't print good
}
