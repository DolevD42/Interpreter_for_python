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
			
		}
		catch (IndentationException e)
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
