
#include "Parse.h"
#include "Expression.h"

using namespace std;


// We love our operators.  Order here determines precedence.
const string operators = "*/+-";

// Clean those dirty tokens
string clean(string token)
{
	string result;
	string whitespace = " \n\t";
	for (unsigned int i = 0; i < token.length(); i++)
	{
		if (whitespace.find(token[i]) == string::npos)
		{
			result.push_back(token[i]);
		}
	}

	return result;
}

// Takes a string and splits it into tokens
list<string> lex(string input)
{
	list<string> tokens;

	string token;
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (operators.find(input[i]) != string::npos)
		{
			// Add any token we've created so far
			if (token.length())
			{
				tokens.push_back(token);
				token.clear();
			}

			// Add this operator as a separate token
			token.push_back(input[i]);
			tokens.push_back(token);
			token.clear();
		}
		else
		{
			// Grow the current token
			token.push_back(input[i]);
		}
	}

	// Any stragglers?
	if (token.length())
	{
		tokens.push_back(token);
	}

	// Clean 'em up
	for (list<string>::iterator i = tokens.begin(); i != tokens.end(); ++i)
	{
		*i = clean(*i);
	}

	return tokens;
}

// Constants
Expression* constantExpression(float rValue)
{
	ConstantExpression* result = new ConstantExpression;
	result->value = rValue;
	return result;
}

// Parse given a left, right, and op
Expression* parseBinary(list<string> left, string op, list<string> right)
{
	BinaryExpression* result = 0;
	if (op == "+")
	{
		result = new BinaryPlus;
	}
	else if (op == "-")
	{
		result = new BinaryMinus;
	}
	else if (op == "*")
	{
		result = new BinaryMultiply;
	}
	else if (op == "/")
	{
		result = new BinaryDivide;
	}

	result->left = parse(left);
	result->right = parse(right);
	return result;
}

// Parse using a given subdivision operator
Expression* splitAndParseBinary(list<string> tokens, string op)
{
	for (list<string>::iterator i = tokens.begin(); i != tokens.end(); ++i)
	{
		if (*i == op)
		{
			list<string> left;
			for (list<string>::iterator j = tokens.begin(); j != i; ++j)
			{
				left.push_back(*j);
			}
			list<string> right;
			for (list<string>::iterator j = ++i; j != tokens.end(); ++j)
			{
				right.push_back(*j);
			}

			return parseBinary(left, op, right);
		}
	}

	return 0;
}

// Takes a list of tokens and returns the expression tree
Expression* parse(list<string> tokens)
{
	// The order of these operators determines the precedence
	for (unsigned int i = 0; i < operators.length(); i++)
	{
		string op;
		op.push_back(operators[i]);
		Expression* result = splitAndParseBinary(tokens, op);
		if (result)
		{
			return result;
		}
	}

	// Must be a constant.
	if(tokens.begin() != tokens.end())
	{
		string token = *tokens.begin();
		float rValue = (float)atof(token.c_str());
		return constantExpression(rValue);
	}
	else
	{
		return constantExpression(0.0f);
	}
}

