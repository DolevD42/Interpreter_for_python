#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Dolev"


int main(int argc, char** argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;
	std::string input_string;
	
	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);

	while (input_string != "quit()")
	{
		// parsing command
		try
		{
			Type* Object = Parser::parseString(input_string);
			if (Object)
			{
				if (Object->isPrintable())
				{
					std::cout << Object->toString() << std::endl;
				}
				if (Object->getTemp() == true)
				{
					delete Object;
				}
			}
			
		}
		catch (IndentationException e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (SyntaxException e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (NameErrorException e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (TypeException e)
		{
			std::cout << e.what() << std::endl;
		}
		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}
	Parser::cleanMemory();
	return 0;
}
