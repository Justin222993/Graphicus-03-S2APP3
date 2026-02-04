/********
* Fichier modifié our créer: morj7100
********/
/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 1 février 2026
 * Description: Déclaration de la classe Canevas. La classe gère un
 *    tableau de couches en accord avec les spécifications de Graphicus.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "forme.h"
#include "couche.h"

using namespace std;

class Canevas
{
public:
	Canevas();
	~Canevas();
	bool reinitialiser();
	bool reinitialiserCouche(int index);
	bool activerCouche(int index);
	bool desactiverCouche(int index);
	bool ajouterForme(Forme *p_forme);
	bool retirerForme(int index);
	double aire();
	bool translater(int deltaX, int deltaY);
	void afficher(ostream & s);
	void ajouterCouche();
	bool retirerCoucheActive();
	int getCoucheActiveIndex();
	void setFormeActive(int index);
	bool retirerFormeActive();
	bool activerPremiereCouche();
	bool activerDerniereCouche();
	bool activerCoucheSuivante();
	bool activerCouchePrecedente();
	bool activerPremiereForme();
	bool activerDerniereForme();
	bool activerFormeSuivante();
	bool activerFormePrecedente();
	int getNombreDeCouches();
	int getIndexFormeActive();
	Couche getCouche(int index);
	void setModePile(bool mode);

private:
	Vecteur<Couche> couches;
	int indexFormeActive = -1;
	bool modePile = false;
};

#endif