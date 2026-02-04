#ifndef PROJECTDEFINITIONS_H
#define PROJECTDEFINITIONS_H

#include "graphicusGUI.h"
#include "canevas.h"
#include <sstream>
#include <QMessageBox>
#include "canevas.h"
#include "forme.h"
#include "carre.h"
#include "cercle.h"
#include "rectangle.h"
#include "graphicusGUI.h"
#include <fstream>

class ProjectDefinitions : public GraphicusGUI {
    Q_OBJECT
public:
    ProjectDefinitions(const char* titre = "Graphicus-03");
    virtual ~ProjectDefinitions();

    // Files and Transformations
    virtual bool ouvrirFichier(const char* nomFichier) override;
    virtual bool sauvegarderFichier(const char* nomFichier) override;
    virtual void coucheTranslater(int deltaX, int deltaY) override;

    // Shapes
    virtual void ajouterCercle(int x, int y, int rayon) override;
    virtual void ajouterRectangle(int x, int y, int long_x, int long_y) override;
    virtual void ajouterCarre(int x, int y, int cote) override;
    virtual void modePileChange(bool mode) override;

    // Menu Canvas (Slots)
    virtual void reinitialiserCanevas() override;
    virtual void coucheAjouter() override;
    virtual void coucheRetirer() override;

    // Menu Shapes (Slots)
    virtual void retirerForme() override;

    // Menu Navigation (Slots)
    virtual void couchePremiere() override;
    virtual void couchePrecedente() override;
    virtual void coucheSuivante() override;
    virtual void coucheDerniere() override;
    virtual void formePremiere() override;
    virtual void formePrecedente() override;
    virtual void formeSuivante() override;
    virtual void formeDerniere() override;

private:
    Canevas canevas;
    ostringstream os;
    void afficherGUI();
};

#endif