/********
* Fichier modifié our créer: morj7100
********/
/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 1 février 2026
 * Modifie par Justin Morissette - 11 Janvier 2026
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gère un vecteur de pointeurs de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H

#include <iostream>
#include "vecteur.h"
#include "forme.h"

class Couche
{
public:
	Couche();
	~Couche();
	bool ajouter(Forme* f);
	Forme* retirer(int index);
	Forme* getForme(int index);
	double getAireTotale();
	bool translater(int x, int y);
	bool reinitialiser();
	bool setInitialiser();
	bool setActive();
	bool setInactive();
	void afficher(ostream & s);
	string getEtat();
	int getNombreDeFormes();
private:
	Vecteur<Forme*> vecteur;
	string etat = "i";
};

#endif
