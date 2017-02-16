/*
 * Expr.cpp
 *
 *  Created on: 14 févr. 2017
 *      Author: lboucaud
 */

#include "Expr.h"


OperateurBinaire::OperateurBinaire(Expr * g, Expr * d) {
	gauche = g;
	droite = d;
}

OperateurBinaire::~OperateurBinaire() {
	delete gauche;
	delete droite;
}

double ExprPlus::operation(double g, double d)
{
	return g + d;
}

double ExprMult::operation(double g, double d)
{
	return g*d;
}
ExprPar::~ExprPar() {
	delete expr;
}
