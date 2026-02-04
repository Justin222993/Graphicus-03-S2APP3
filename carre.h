/********
* Fichier modifié our créer: morj7100
********/
/********
 * Fichier: carre.h
 * Auteurs: Justin Morissette
 * Date: 1 février 2026
 * Description: header file de Classe carre dérivé de la classe forme
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CARRE_H
#define CARRE_H

#include <iostream>
#include "forme.h"

using namespace std;

class Carre : public Forme
{
public:
	Carre(int x, int y, double cote);
	Carre();
	~Carre();
	virtual double aire();
	virtual void afficher(ostream & s);
private:
	double cote;
};

#endif
