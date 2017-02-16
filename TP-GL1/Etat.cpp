/*
 * Etat.cpp
 *
 *  Created on: 14 févr. 2017
 *      Author: lboucaud
 */

#include "Etat.h"
//#include "Expr.h"
#include "Automate.h"


Etat::~Etat() {
	// TODO Auto-generated destructor stub
}

bool E0::transition (Automate & automate,Symbole *s)
{
    switch (*s){
        case NOMBRE:
        automate.decalage(s, new E3);
        break;
        case EXPR:
        automate.decalage(s, new E1);
        break;
        case OUVREPAR:
        automate.decalage(s, new E2);
        break;
    }
    return false;
}

bool E1::transition (Automate & automate,Symbole *s)
{
    switch (*s){
        case PLUS:
        automate.decalage(s, new E4);
        break;
        case MLTI:
        automate.decalage(s, new E5);
        break;
        default:
        Expr *s1=(Expr*) automate.popSymbol();
        automate.reduction(1,s1);

    }
    return false;
}

bool E2::transition (Automate & automate,Symbole *s)
{
    switch (*s){
        case OUVREPAR:
        automate.decalage(s, new E2());
        break;
        case NOMBRE:
        automate.decalage(s, new E3);
        break;
        case EXPR:
        automate.decalage(s, new E6);
        break;
    }
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
	Expr *s1 = (Expr *)automate.popSymbol();
	automate.reduction(1, s1);
	return true;
}

E3::~E3() {
	// TODO Auto-generated destructor stub
}


bool E4::transition (Automate & automate,Symbole *s)
{
    switch (*s){
        case EXPR:
        automate.decalage(s,new E7);
        break;
        case NOMBRE:
        automate.decalage(s,new E3);
        break;
        case OUVREPAR:
        automate.decalage(s, new E2);
        break;
    }
    return false;
}

bool E5::transition(Automate & automate,Symbole *s)
{
    switch (*s){
        case OUVREPAR:
        automate.decalage(s,new E2);
        break;
        case EXPR:
        automate.decalage(s,new E8);
        break;
        case NOMBRE:
        automate.decalage(s,new E3);
        break;

    }
    return false;
}

bool E6::transition(Automate & automate,Symbole *s)
{
    switch (*s){
        case PLUS:
        automate.decalage(s,new E4);
        break;
        case MLTI:
        automate.decalage(s,new E5);
        break;
        case NOMBRE:
        automate.decalage(s,new E9);
        break;
        }
    return false;
}

bool E7::transition(Automate & automate,Symbole *s)
{
    switch (*s){
        case MLTI:
        automate.decalage(s,new E5);
        break;
        default:
        Expr * s1 =(Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2=(Expr*) automate.popSymbol();
        automate.reduction(3, new ExprPlus(s2,s1));
    }
    return false;
}

bool E8::transition(Automate & automate, Symbole*s) {
	Expr * s1 = (Expr*)automate.popSymbol();
	automate.popAndDestroySymbol();
	Expr * s2 = (Expr*)automate.popSymbol();
	automate.reduction(3, new ExprMult(s2, s1));
	return true;
}

bool E9::transition(Automate & automate, Symbole*s) {
	automate.popAndDestroySymbol();
	Expr * s1 = (Expr*)automate.popSymbol();
	automate.popAndDestroySymbol();
	automate.reduction(3, new ExprPar(s1));
	return true;
}

E9::~E9() {
	// TODO Auto-generated destructor stub
}

