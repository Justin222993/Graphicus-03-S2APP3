/********
* Fichier modifié our créer: morj7100
********/
/********
 * Fichier: forme.cpp
 * Auteurs: C.-A. Brunet
 * Date: 1 février 2026
 * Description: Implémentation des méthodes des classes décrites dans
 *    forme.h. Les méthodes de la classe Forme ne doivent pas être
 *    modifiées.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "forme.h"

Forme::Forme(int x1, int y1)
{
	ancrage.x = x1;
	ancrage.y = y1;
}

Forme::~Forme()
{
}

void Forme::translater(int deltaX, int deltaY)
{
	ancrage.x += deltaX;
	ancrage.y += deltaY;
}

Coordonnee Forme::getAncrage()
{
	return ancrage;
}

void Forme::setAncrage(Coordonnee c)
{
	ancrage = c;
}
