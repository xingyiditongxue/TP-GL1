#ifndef LEXER_H_
#define LEXER_H_

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
	Lexer(istream &inputStream) : is(inputStream) {}
	void consumeWordIgnored();
	lexReturn * lex();
	Symbole* getNext();
	virtual ~Lexer() {};

	int next(void);
	void shift(void);
};

#endif // !LEXER_H_