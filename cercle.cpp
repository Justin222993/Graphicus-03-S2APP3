/********
* Fichier modifié our créer: morj7100
********/
/********
* Fichier: cercle.cpp
 * Auteurs: Justin Morissette
 * Date: 1 février 2026
 * Description: main file Classe cercle dérivé de la classe forme
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "cercle.h"

Cercle::Cercle(int x, int y, double rayon): Forme(x,y), rayon(rayon)
{
}

Cercle::Cercle(): Forme(1,1), rayon(1)
{
}

Cercle::~Cercle(){}

double Cercle::aire() {
 return M_PI * pow(rayon,2);
}

void Cercle::afficher(ostream & s) {
 Coordonnee c = getAncrage();
 s << "C " << c.x << " " << c.y << " " << rayon << endl;
}