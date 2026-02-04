
#include "projectDefinitions.h"

// Fun:
//this->message("Cercle ajoute !");
//this->messageErreur("Cercle ajoute !");

ProjectDefinitions::ProjectDefinitions(const char* titre) : GraphicusGUI(titre) {

}

ProjectDefinitions::~ProjectDefinitions() {

}

// Fichier
#include <fstream>
#include <sstream>
#include <string>

bool ProjectDefinitions::ouvrirFichier(const char* nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        this->messageErreur("Impossible d'ouvrir le fichier.");
        return false;
    }

    canevas.reinitialiser();
    int indexCoucheCourante = 0;

    string ligne;
    while (getline(fichier, ligne)) {
        if (ligne.empty()) continue;

        istringstream iss(ligne);
        char type;
        iss >> type;

        if (type == 'L') {
            if (indexCoucheCourante > 0) {
                canevas.ajouterCouche();
                canevas.activerCouche(indexCoucheCourante);
            }
            indexCoucheCourante++;
        }
        else if (type == 'R' || type == 'C' || type == 'K') {
            Forme* nouvelleForme = nullptr;
            int x, y, v1, v2;

            if (type == 'R') {
                if (iss >> x >> y >> v1 >> v2) nouvelleForme = new Rectangle(x, y, v1, v2);
            }
            else if (type == 'C') {
                if (iss >> x >> y >> v1) nouvelleForme = new Cercle(x, y, v1);
            }
            else if (type == 'K') {
                if (iss >> x >> y >> v1) nouvelleForme = new Carre(x, y, v1);
            }

            if (nouvelleForme) {
                canevas.ajouterForme(nouvelleForme);
            }
        }
    }

    fichier.close();
    afficherGUI();
    this->message("Canevas reconstruit avec les bonnes couches !");
    return true;
}

bool ProjectDefinitions::sauvegarderFichier(const char* nomFichier) {
    ofstream fichier(nomFichier);

    if (!fichier.is_open()) {
        this->messageErreur("Erreur : Impossible de creer le fichier de sauvegarde.");
        return false;
    }

    canevas.afficher(fichier);
    fichier.close();

    this->message("Canevas sauvegarde avec succes !");
    return true;
}

// Formes/Couches
void ProjectDefinitions::coucheTranslater(int deltaX, int deltaY) {
    canevas.translater(deltaX, deltaY);

    afficherGUI();
}

void ProjectDefinitions::ajouterCercle(int x, int y, int rayon)
{
    Cercle* nouveauRectangle = new Cercle(x, y, rayon);

    canevas.ajouterForme(nouveauRectangle);

    afficherGUI();
}

void ProjectDefinitions::ajouterRectangle(int x, int y, int l, int h)
{
    Rectangle* nouveauRectangle = new Rectangle(x, y, l, h);

    canevas.ajouterForme(nouveauRectangle);

    afficherGUI();
}

void ProjectDefinitions::ajouterCarre(int x, int y, int cote)
{
    Carre* nouveauCarre = new Carre(x, y, cote);

    canevas.ajouterForme(nouveauCarre);

    afficherGUI();
}

void ProjectDefinitions::modePileChange(bool mode) {
    canevas.setModePile(mode);

    if (mode) {
        this->message("Mode Pile active : les formes s'empilent !");
    }
    else {
        this->message("Mode File active : les formes s'ajoutent normalement.");
    }

    afficherGUI();
}

void ProjectDefinitions::reinitialiserCanevas() {
    canevas.reinitialiser();
    
    afficherGUI();
}

void ProjectDefinitions::coucheAjouter() {
    canevas.ajouterCouche();
}

void ProjectDefinitions::coucheRetirer() {
    if (!canevas.retirerCoucheActive()) {
        this->messageErreur("On ne peut pas retirer la derniere couche.");
    }
    afficherGUI();
}

void ProjectDefinitions::retirerForme() {
    if (!canevas.retirerFormeActive()) {
        this->message("Pas de forme a effacer sur la couche active.");
    }

    afficherGUI();
}

void ProjectDefinitions::couchePremiere() {
    if (!canevas.activerPremiereCouche()) {
        this->messageErreur("Activation de la premiere couche a echoue.");
    }
    afficherGUI();
}

void ProjectDefinitions::couchePrecedente() {
    if (!canevas.activerCouchePrecedente()) {
        this->message("Nous sommes deja sur la premiere couche.");
    }
    afficherGUI();
}

void ProjectDefinitions::coucheSuivante() {
    if (!canevas.activerCoucheSuivante()) {
        this->message("Nous sommes deja sur la derniere couche.");
    }
    afficherGUI();
}

void ProjectDefinitions::coucheDerniere() {
    if (!canevas.activerDerniereCouche()) {
        this->messageErreur("Activation de la derniere couche a echoue.");
    }
    afficherGUI();
}

void ProjectDefinitions::formePremiere() {
    if (!canevas.activerPremiereForme()) {
        this->messageErreur("Activation de la premiere forme a echoue.");
    }
    afficherGUI();
}

void ProjectDefinitions::formePrecedente() {
    if (!canevas.activerFormePrecedente()) {
        this->message("Nous somme deja sur la premiere forme.");
    }
    afficherGUI();
}

void ProjectDefinitions::formeSuivante() {
    if (!canevas.activerFormeSuivante()) {
        this->message("Nous sommes deja sur la derniere forme.");
    }
    afficherGUI();
}

void ProjectDefinitions::formeDerniere() {
    if (!canevas.activerDerniereForme()) {
        this->message("Nous sommes deja sur la derniere forme.");
    }
    afficherGUI();
}

void ProjectDefinitions::afficherGUI() {
    // 1. Initialisation complète à zéro pour éviter les nombres bizarres (ex: -858993460)
    Informations info = {};
    ostringstream os;

    // --- NIVEAU CANEVAS ---
    info.nbCouches = canevas.getNombreDeCouches();
    info.coucheActive = canevas.getCoucheActiveIndex();
    info.aireCanevas = canevas.aire();

    int totalFormes = 0;
    for (int i = 0; i < info.nbCouches; i++) {
        totalFormes += canevas.getCouche(i).getNombreDeFormes();
    }
    info.nbFormesCanevas = totalFormes;

    // Couches
    if (info.coucheActive >= 0) {
        Couche c = canevas.getCouche(info.coucheActive);
        info.nbFormesCouche = c.getNombreDeFormes();
        info.aireCouche = c.getAireTotale();
        info.formeActive = canevas.getIndexFormeActive();

        string etatStr = c.getEtat();
        int j = 0;
        for (; j < etatStr.length() && j < (sizeof(info.etatCouche) - 1); j++) {
            info.etatCouche[j] = etatStr[j];
        }
        info.etatCouche[j] = '\0';

        // Formes
        if (info.formeActive >= 0 && info.formeActive < info.nbFormesCouche) {
            Forme* f = c.getForme(info.formeActive);
            if (f != nullptr) {
                info.coordX = f->getAncrage().x;
                info.coordY = f->getAncrage().y;
                info.aireForme = f->aire();

                const char* msg = "Forme active";
                int k = 0;
                for (; msg[k] != '\0' && k < (sizeof(info.informationForme) - 1); k++) {
                    info.informationForme[k] = msg[k];
                }
                info.informationForme[k] = '\0';
            }
        }
        else {
            info.coordX = 0;
            info.coordY = 0;
            info.aireForme = 0;

            // Si il y a pas de formes actives for some reason
            const char* msg = "Aucune forme active";
            int k = 0;
            for (; msg[k] != '\0' && k < (sizeof(info.informationForme) - 1); k++) {
                info.informationForme[k] = msg[k];
            }
            info.informationForme[k] = '\0';
        }
    }
    else {
        info.nbFormesCouche = 0;
        info.aireCouche = 0;
        info.coordX = 0;
        info.coordY = 0;

        // "N/A" et "-"
        info.etatCouche[0] = 'N'; info.etatCouche[1] = '/'; info.etatCouche[2] = 'A'; info.etatCouche[3] = '\0';
        info.informationForme[0] = '-'; info.informationForme[1] = '\0';
    }

    // --- ENVOI ET DESSIN ---
    this->setInformations(info);
    os.str("");
    os.clear();
    canevas.afficher(os);
    dessiner(os.str().c_str());
}