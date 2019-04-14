#ifndef INCLUDED_PARSE_H
#define INCLUDED_PARSE_H

#include <string>
#include <list>

class Expression;

std::list<std::string> lex(std::string input);
Expression* parse(std::list<std::string> tokens);

#endif
