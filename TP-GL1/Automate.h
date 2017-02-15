/*
 * Automate.h
 *
 *  Created on: 14 févr. 2017
 *      Author: lboucaud
 */

#ifndef AUTOMATE_H_
#define AUTOMATE_H_
#include <stack>
using namespace std;
#include "Symbole.h"
#include "Etat.h"
#include "Lexer.h"
class Etat;
class Automate {
protected:
	stack<Symbole*> symbolstack;
	stack<Etat*> statestack;
	Lexer lexer;
public:
	Automate();
	virtual ~Automate(){};

	void decalage(Symbole * s, Etat * e);
	void reduction(int n, Symbole *s);
	Symbole * topSymbol();
	void popAndDestroySymbol();
	//Symbole * exprPlus(Symbole * s1, Symbole * s2);
};


#endif /* AUTOMATE_H_ */
