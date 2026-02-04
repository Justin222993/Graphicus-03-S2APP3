/********
* Fichier modifié our créer: morj7100
********/
/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 1 février 2026
 * Modifie par Justin Morissette - 11 Janvier 2026
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche() {
    etat = "i";
}

Couche::~Couche() {
    vecteur.vider();
}

bool Couche::ajouter(Forme* pointeur) {
    return vecteur.ajouter(pointeur);
}

Forme* Couche::retirer(int index) {
    return vecteur.retirer(index);
}

Forme* Couche::getForme(int index) {
    return vecteur.get(index);
}

double Couche::getAireTotale() {
    int taille = vecteur.getTaille();

    double aireTotale = 0;

    for (int i = 0; i < taille; i++) {
        aireTotale += vecteur.get(i)->aire();
    }

    return aireTotale;
}

bool Couche::translater(int x, int y) {
    try {
        for (int i = 0; i < vecteur.getTaille(); i++) {
            vecteur.get(i)->translater(x, y);
        }
    } catch (...) {
        return false;
    }
    return true;
}

bool Couche::reinitialiser() {
    try {
        vecteur.vider();
        etat = "i";
    }
    catch (...) {
        return false;
    }
    return true;
}

bool Couche::setInitialiser() {
    try {
        etat = "i";
    }
    catch (...) {
        return false;
    }
    return true;
}

bool Couche::setActive() {
    try {
        etat = "a";
    }
    catch (...) {
        return false;
    }
    return true;
}

bool Couche::setInactive() {
    try {
        etat = "x";
    }
    catch (...) {
        return false;
    }
    return true;
}

string Couche::getEtat() {
    return etat;
}


void Couche::afficher(ostream & s) {
    s << "L " << etat << endl;
    if (vecteur.getTaille() != 0) {
        for (int i = 0; i < vecteur.getTaille(); i++) {
            if (vecteur.get(i) != nullptr) {
                Forme* f = (vecteur.get(i));
                f->afficher(s);
            } else {
                s << "nullptr";
            }
        }
    }
}

int Couche::getNombreDeFormes() {
    return vecteur.getTaille();
}