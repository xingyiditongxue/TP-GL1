/*
 * Automate.cpp
 *
 *  Created on: 14 févr. 2017
 *      Author: lboucaud
 */

#include "Automate.h"

void Automate::decalage(Symbole *s , Etat *e)
{
	symbolstack.push(s);
	statestack.push(e);
}
void Automate::reduction(int n, Symbole *s){
	for(int i=0;i<n;i++){
		delete ( statestack.top());
		statestack.pop();
	}
	lexer->putSymbol(s);
}

Symbole * Automate::topSymbol() {
	symbolstack.top();
}

void Automate::popAndDestroySymbol() {
	delete(symbolstack.top());
	symbolstack.pop();
}

//Symbole * Automate::exprPlus(Symbole * s1, Symbole * s2) {
//
//}




