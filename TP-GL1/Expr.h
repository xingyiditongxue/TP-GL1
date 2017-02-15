/*
 * Expr.h
 *
 *  Created on: 14 févr. 2017
 *      Author: lboucaud
 */

#ifndef EXPR_H_
#define EXPR_H_
#include "Symbole.h"

class Expr : public Symbole{
public:
	Expr():Symbole(EXPR){}
	virtual ~Expr(){}
};

#endif /* EXPR_H_ */
