///
/// \file Application.h
/// \brief L'application, gestionnaire des managers.
/// \author Erwan Normand
/// \date 10 juin 2014
///

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "CreditsManager.h"
#include "CategorieManager.h"
#include "Dossier.h"
#include "FormationManager.h"
#include "Inscription.h"
#include "NoteManager.h"
#include "PeriodeManager.h"
#include "UVManager.h"

class Application : Manager
{
private:
    QString chemin_dossiers; // Le chemin du dossier de stockage des xml des Dossiers
    QString chemin_dossier; // Le chemin du dossier de stockage des xml du Dossier chargé
    //QString fichier; // Le nom du fichier de configration du Dossier chargé (hérité de Manager)
    QString chemin_default; // Le chemin du dossier de stockage des xml par défault
    QString fichier_default; // Le nom du fichier de configuration par défault
    NoteManager notman;
    CategorieManager catman;
    CreditsManager credman;
    UVManager uvman;
    FormationManager forman; // A factoriser dans un Factory
    FormationManager filman;
    PeriodeManager periodeman;
    Dossier dossier;

    //void setDossier(const Dossier& d) { dossier = &d; }

    void initialiser();
    void chargerConfiguration();
    void sauvegarderConfiguration();

public:
    Application(const QString& cdos, const QString& cdef, const QString& f): Manager(f), chemin_dossiers(cdos), chemin_dossier(), chemin_default(cdef), fichier_default(f),
        notman(), catman(), credman(), uvman(), forman(), filman(), periodeman(), dossier() {}

    ~Application() { fermer(); }

    void nouveau(const QString& nom, const QString& prenom);
    void charger(const QString& f = "");
    void sauvegarder();
    void fermer();

    bool estFerme() const;

    NoteManager& getNoteManager() { return notman; }
    const NoteManager& getNoteManager() const { return notman; }

    CategorieManager& getCategorieManager() { return catman; }
    const CategorieManager& getCategorieManager() const { return catman; }

    CreditsManager& getCreditsManager() { return credman; }
    const CreditsManager& getCreditsManager() const { return credman; }

    UVManager& getUVManager() { return uvman; }
    const UVManager& getUVManager() const { return uvman; }

    FormationManager& getFormationManager() { return forman; }
    const FormationManager& getFormationManager() const { return forman; }

    FormationManager& getFiliereManager() { return filman; }
    const FormationManager& getFiliereManager() const { return filman; }

    PeriodeManager& getPeriodeManager() { return periodeman; }
    const PeriodeManager& getPeriodeManager() const { return periodeman; }

    Dossier& getDossier() { return dossier; }
    const Dossier& getDossier() const { return dossier; }

    /*void setNoteManager(const NoteManager& n) { notman = &n; }
    void setCategorieManager(const CategorieManager& c) { catman = &c; }
    void setCreditsManager(const CreditsManager& uv) { credman = &uv; }
    void setUVManager(const UVManager& uv) { uvman = &uv; }
    void setFormationManager(const FormationManager& f) { forman = &f; }
    void setFiliereManager(const FormationManager& f) { filman = &f; }
    void setPeriodeManager(const PeriodeManager& p) { periodeman = &p; }*/
};

#endif // APPLICATION_H
