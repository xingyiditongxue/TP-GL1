#include "Lexer.h"

void Lexer::consumeWordIgnored() {
	// lorsqu'on consomme un espace, ou un changement de ligne, ou un saut.
	if (this->is.peek() == ' ' || this->is.peek() == '\n' || this->is.peek() == '\t') {
		this -> is.ignore();
	}
}

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