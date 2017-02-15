#ifndef LEXE_H_
#define LEXE_H_
#endif // !LEXE.H

#include "Symbole.h"
#include <iostream>
using namespace std;

enum class lexReturnType { Eof, Error, Symbole };
union lexReturnValue { 
	bool end = false;
	Symbole * symbol;
};
struct lexReturn {
	lexReturnType returnType;
	lexReturnValue returnValue;
};
class Lexer {
protected:
	istream &is;
	struct LexReturn {
		int returnValue;

	};
public:
	Lexer();
	virtual ~Lexer() {};
	void consumeWordIgnored();
	lexReturn * lex();
	
};