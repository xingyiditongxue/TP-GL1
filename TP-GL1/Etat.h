/*
 * Etat.h
 *
 *  Created on: 14 févr. 2017
 *      Author: lboucaud
 */

#ifndef ETAT_H_
#define ETAT_H_

#include <string>
using namespace std;

#include "Symbole.h"
#include "Expr.h"
class Automate;
class Etat {
protected:
	string name;
public:
	Etat(string name) { this->name = name; };
	Etat() {};
	virtual ~Etat();
	void print() const;
	virtual bool transition(Automate & automate, Symbole*s)=0;

};

class E0: public Etat {
public:
	E0() : Etat("E0") {};
	bool transition(Automate & automate, Symbole*s);
	virtual ~E0() {
	}
	;
};

class E1: public Etat {
public:
	E1() : Etat("E1") {};
	bool transition(Automate & automate, Symbole*s);
	virtual ~E1() {};
};

class E2: public Etat {
public:
	E2() : Etat("E2") {};
	bool transition(Automate & automate, Symbole*s);
	virtual ~E2() {};
};

class E3: public Etat {
public:
	E3() : Etat("E3") {};
	virtual ~E3();
	bool transition(Automate & automate, Symbole*s);
};

class E4: public Etat {
public:
	E4() : Etat("E4") {};
	bool transition(Automate & automate, Symbole*s);
	virtual ~E4() {};
};

class E5: public Etat {
public:
	E5() : Etat("E5") {};
	bool transition(Automate & automate, Symbole*s);
	virtual ~E5() {};
};

class E6: public Etat {
public:
	E6() : Etat("E6") {};
	bool transition(Automate & automate, Symbole*s);
	virtual ~E6() {};
};

class E7: public Etat {
public:
	E7() : Etat("E7") {};
	bool transition(Automate & automate, Symbole*s);
	virtual ~E7() {};
};

class E8: public Etat {
public:
	E8() : Etat("E8") {};
	bool transition(Automate & automate, Symbole*s);
	virtual ~E8() {};
};

class E9: public Etat {
public:
	E9() : Etat("E9") {};
	virtual ~E9();
	bool transition(Automate & automate, Symbole*s);
};
#endif /* ETAT_H_ */
