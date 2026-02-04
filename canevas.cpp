/********
* Fichier modifié our créer: morj7100
********/
/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 1 février 2026
 * Description: Implémentation des méthodes des classes décrites dans
 *    canevas.h.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
	ajouterCouche();
	couches[0].setActive();
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
	couches.vider();
	ajouterCouche();
	return couches[0].setActive();
}

bool Canevas::reinitialiserCouche(int index)
{
	return couches[index].reinitialiser();
}

bool Canevas::activerCouche(int index)
{
	if (index < 0 || index >= couches.getTaille())
		return false;

	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == "a")
			desactiverCouche(i);
	}

	return couches[index].setActive();
}

bool Canevas::desactiverCouche(int index)
{
	if (index < 0 || index >= couches.getTaille())
		return false;
	return couches[index].setInactive();
}

bool Canevas::ajouterForme(Forme *p_forme)
{
	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == "a") {
			indexFormeActive = couches[i].getNombreDeFormes();
			return couches[i].ajouter(p_forme);
		}
	}
	return false;
}

bool Canevas::retirerForme(int index)
{
	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == "a") {

			if (couches[i].getNombreDeFormes() <= 0) {
				return false;
			}

			bool success = couches[i].retirer(index);

			if (success) {
				int nbRestant = couches[i].getNombreDeFormes();

				if (indexFormeActive >= nbRestant && nbRestant > 0) {
					indexFormeActive = nbRestant - 1;
				}

				else if (nbRestant == 0) {
					indexFormeActive = 0;
				}
			}

			return success;
		}
	}
	return false;
}

double Canevas::aire()
{
	double aireTotaleCanevas = 0;

	for (int i = 0; i < couches.getTaille(); i++) {
		aireTotaleCanevas += couches[i].getAireTotale();
	}
	return aireTotaleCanevas;
}

bool Canevas::translater(int deltaX, int deltaY)
{
	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == "a") {
			return couches[i].translater(deltaX, deltaY);
		}
	}
	return false;
}

void Canevas::afficher(ostream& s)
{
	for (int i = 0; i < couches.getTaille(); i++) {
		couches[i].afficher(s);
	}
}

void Canevas::ajouterCouche()
{
	Couche nouvelleCouche;
	couches += nouvelleCouche;
}

bool Canevas::retirerCoucheActive() {
	int indexActive = -1;

	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == "a") {
			indexActive = i;
			break;
		}
	}

	if (indexActive == -1 || couches.getTaille() <= 1) {
		return false;
	}

	couches[indexActive].reinitialiser();
	couches.retirer(indexActive);

	couches[0].setActive();

	return true;
}

int Canevas::getCoucheActiveIndex() {
	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == "a") {
			return i;
		}
	}

	return -1;
}

bool Canevas::retirerFormeActive() {
	return retirerForme(indexFormeActive);
}

void Canevas::setFormeActive(int index) {
	indexFormeActive = index;
}

bool Canevas::activerPremiereCouche() {
	return activerCouche(0);
}

bool Canevas::activerDerniereCouche() {
	return activerCouche(couches.getTaille() - 1);
}

bool Canevas::activerCoucheSuivante() {
	int indexActive = getCoucheActiveIndex();

	if (indexActive != -1 && indexActive < couches.getTaille() - 1) {
		return activerCouche(indexActive + 1);
	}
	return false;
}

bool Canevas::activerCouchePrecedente() {
	int indexActive = getCoucheActiveIndex();

	if (indexActive > 0) {
		return activerCouche(indexActive - 1);
	}
	return false;
}

bool Canevas::activerPremiereForme() {
	int index = getCoucheActiveIndex();
	if (index != -1 && couches[index].getNombreDeFormes() > 0) {
		indexFormeActive = 0;
		return true;
	}
	return false;
}

bool Canevas::activerDerniereForme() {
	int index = getCoucheActiveIndex();
	if (index != -1 && couches[index].getNombreDeFormes() > 0) {
		indexFormeActive = couches[index].getNombreDeFormes() - 1;
		return true;
	}
	return false;
}

bool Canevas::activerFormeSuivante() {
	int index = getCoucheActiveIndex();
	if (index != -1 && indexFormeActive < couches[index].getNombreDeFormes() - 1) {
		indexFormeActive++;
		return true;
	}
	return false;
}

bool Canevas::activerFormePrecedente() {
	int index = getCoucheActiveIndex();
	if (index != -1 && indexFormeActive > 0) {
		indexFormeActive--;
		return true;
	}
	return false;
}

int Canevas::getNombreDeCouches() {
	return couches.getTaille();
}

int Canevas::getIndexFormeActive() {
	return indexFormeActive;
}

Couche Canevas::getCouche(int index) {
	return couches[index];
}

void Canevas::setModePile(bool mode) {
	if (this->modePile == mode) return;

	this->modePile = mode;

	int coucheActiveIndex = -1;

	for (int i = 0; i < couches.getTaille(); i++) {
		if (couches[i].getEtat() == "a") {
			coucheActiveIndex = i;
		}
	}

	int n = getNombreDeCouches();
	if (n > 1) {
		for (int i = 0; i < n / 2; i++) {
			Couche temp = couches[i];
			couches[i] = couches[n - 1 - i];
			couches[n - 1 - i] = temp;
		}
	}

	if (n > 0) {
		activerCouche((n - 1) - coucheActiveIndex);
	}
}