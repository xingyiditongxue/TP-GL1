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

class OperateurBinaire : public Expr {
public:
	OperateurBinaire(Expr * g, Expr * d);
	~OperateurBinaire();
	//double Evaluation(const Vars & variables);
protected:
	virtual double operation(double g, double d) = 0;
	Expr * gauche;
	Expr * droite;
};

class ExprPlus : public OperateurBinaire {
public:
	ExprPlus(Expr * g, Expr * d) : OperateurBinaire(g, d) {};
	~ExprPlus() {};
protected:
	double operation(double g, double d);
};

class ExprMult : public OperateurBinaire {
public:
	ExprMult(Expr * g, Expr * d) : OperateurBinaire(g, d) {};
	~ExprMult() {};
protected:
	double operation(double g, double d);
};

class ExprPar : public Expr {
public:
	ExprPar(Expr * e) :expr(e) {};
	~ExprPar();
protected:
	Expr * expr;
	//double operation(double g, double d);
};

#endif /* EXPR_H_ */
