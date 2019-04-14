
#include "Expression.h"
#include "Parse.h"

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[])
{
	string input;

	while (getline(cin, input))
	{
		list<string> tokens = lex(input);
		Expression* expression = parse(tokens);
		float rValue = expression->evaluate();
		printf("%f\n", rValue);
		delete expression;
	}

	return 0;
}
