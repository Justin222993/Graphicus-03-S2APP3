/********
* Fichier modifié our créer: morj7100
********/
/********
 * Fichier: rectangle.h
 * Auteurs: Justin Morissette
 * Date: 1 février 2026
 * Description: header file de Classe rectangle dérivé de la classe forme
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "forme.h"

using namespace std;

class Rectangle : public Forme
{
public:
	Rectangle(int x, int y, double largeur, double hauteur);
	Rectangle();
	~Rectangle();
	virtual double aire();
	virtual void afficher(ostream & s);
private:
	double largeur;
	double hauteur;
};

#endif
