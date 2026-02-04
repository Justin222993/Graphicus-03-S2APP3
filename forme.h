/********
* Fichier modifié our créer: morj7100
********/
/********
 * Fichier: forme.h
 * Auteurs: C.-A. Brunet
 * Date: 1 février 2026
 * Description: Déclaration des classes de formes géométriques. La
 *    classe Forme ne doit pas être modifiée.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef FORME_H
#define FORME_H

#include <iostream>
#include "coordonnee.h"

using namespace std;

class Forme
{
public:
	Forme(int x = 0, int y = 0);
	virtual ~Forme();
	void translater(int deltaX, int deltaY);
	Coordonnee getAncrage();
	void setAncrage(Coordonnee c);
	virtual double aire() = 0;
	virtual void afficher(ostream & s) = 0;
protected:
	Coordonnee ancrage;
};

#endif
