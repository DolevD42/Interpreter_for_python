#include "SyntaxException.h"

const char* SyntaxException::what() const noexcept
{
	return "SyntaxException: invalid syntax";
}
