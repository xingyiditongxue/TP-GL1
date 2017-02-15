/*
 * Symbole.h
 *
 *  Created on: 14 févr. 2017
 *      Author: lboucaud
 */

#ifndef SYMBOLE_H_
#define SYMBOLE_H_
#include <iostream>
using namespace std;
enum symbole {NOMBRE=0,EXPR=1,MLTI=2,PLUS=3,FERMEPAR=4,OUVREPAR=5};
class Symbole {
protected:
	int ident;
public:
	Symbole(int id) : ident(id){}
	virtual ~Symbole(){}
	void print();
	operator int() const{return ident;}

};

#endif /* SYMBOLE_H_ */
