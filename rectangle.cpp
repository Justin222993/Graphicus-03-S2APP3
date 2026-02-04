/********
* Fichier modifié our créer: morj7100
********/
/********
* Fichier: rectangle.cpp
 * Auteurs: Justin Morissette
 * Date: 1 février 2026
 * Description: main file Classe rectangle dérivé de la classe forme
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "rectangle.h"

Rectangle::Rectangle(int x, int y, double largeur, double hauteur) : Forme(x, y), largeur(largeur), hauteur(hauteur)
{
}

Rectangle::Rectangle() : Forme(1, 1), largeur(1), hauteur(1)
{
}

Rectangle::~Rectangle(){}

double Rectangle::aire() {
 return largeur * hauteur;
}

void Rectangle::afficher(ostream & s) {
 Coordonnee c = getAncrage();
 s << "R " << c.x << " " << c.y << " " << largeur << " " << hauteur << endl;
}