/********
* Fichier modifié our créer: morj7100
********/
/********
* Fichier: carre.cpp
 * Auteurs: Justin Morissette
 * Date: 1 février 2026
 * Description: main file Classe carre dérivé de la classe forme
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "carre.h"

Carre::Carre(int x, int y, double cote): Forme(x,y), cote(cote)
{
}

Carre::Carre(): Forme(1, 1), cote(1)
{
}

Carre::~Carre(){}

double Carre::aire() {
 return cote * cote;
}

void Carre::afficher(ostream & s) {
 Coordonnee c = getAncrage();
 s << "K " << c.x << " " << c.y << " " << cote << endl;
}