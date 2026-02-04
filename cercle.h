/********
* Fichier modifié our créer: morj7100
********/
/********
 * Fichier: cercle.h
 * Auteurs: Justin Morissette
 * Date: 1 février 2026
 * Description: header file de Classe cercle dérivé de la classe forme
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CERCLE_H
#define CERCLE_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "forme.h"

using namespace std;

class Cercle : public Forme
{
public:
	Cercle(int x, int y, double rayon);
	Cercle();
	~Cercle();
	virtual double aire();
	virtual void afficher(ostream & s);
private:
	double rayon;
};

#endif
