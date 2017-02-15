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
class Etat;
class Automate {
protected:
	stack<Symbole*> symbolstack;
	stack<Etat*> statestack;
public:
	Automate();
	virtual ~Automate(){};

	void decalage(Symbole * s, Etat * e);
	void reduction(int n, Symbole *s);
};


#endif /* AUTOMATE_H_ */
