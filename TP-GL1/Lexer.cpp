#include "Lexer.h"
#include <ctype.h>
#include <cstdio>

void Lexer::consumeWordIgnored() {
	// lorsqu'on consomme un espace, ou un changement de ligne, ou un saut.
	if (this->is.peek() == ' ' || this->is.peek() == '\n' || this->is.peek() == '\t') {
		this -> is.ignore();
	}
}

Symbole* Lexer::getNext()
{
	char c = cin.peek();
	if (c == '+' || c == '*' || c == '(' || c == ')')
	{
		return new Symbole(c);
	}
	else if (isdigit(c))
	{
		string chain = "";
		chain += c;
		shift();
		while (isdigit(c))
		{
			c = cin.peek();
			chain += c;
			shift();
		}
	}
	else if (c == EOF)
	{
		return new Symbole(FIN);
	}
	else if (c == ' ' || c == '\t' || c == '\n')
	{
		shift();
		return NULL;
	}
	return NULL;
}

void Lexer::shift(void)
{
	cin.get();
}

void Lexer::putSymbol(Symbole *s) {}

lexReturn * Lexer::lex() {
	this->consumeWordIgnored();
	int input = this->is.peek();

	if (this->is.end) {
		lexReturnValue returnValue;
		returnValue.end = true;
		return new lexReturn{ lexReturnType::Eof , returnValue};
	}

	switch (input) {
		case ('+') {

		}
	}

}