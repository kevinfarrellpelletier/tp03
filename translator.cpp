#include "translator.h"
#include <iostream>

Translator::Translator(std::string fichierInput, std::string fichierOutput) {
    this->fichierInput = fichierInput;
    this->fichierOutput = fichierOutput;
}

Translator::~Translator() {

    for (Produit* produit : produits) {
        delete produit;
    }
    produits.clear();
}

void Translator::extract() {
    std::string id = "";
    std::string description = "";
    double prix = -1;
    Produit* produit;

    std::ifstream infile(fichierInput);

    for (std::string line; getline(infile, line); ) {

        //check si la ligne a un ':' dedans ET si prix est vide. Si oui, formate et store dans 'id'
        if ((line.find(":") != std::string::npos) && (prix == -1)) {
            id = line;
        }
        //check si ligne contient seulement nombres.  Si oui, formate et store dans 'prix'
        else if (onlyNumbers(line)) {
            prix = formatPrix(line);
        }
        //sinon la ligne est une description
        else {
            description = line;
        }

        //creation du Produit et insertion dans le Vector.  Reinitialisation des variables locales.
        if ((id != "") && (prix != -1)) {
            produit = new Produit(id, description, prix);
            produits.push_back(produit);
            id = "";
            description = "";
            prix = -1;
        }
    }
    infile.close();
}

std::string Translator::formatId(std::string id) {
    char courant;
    std::string resultat;

    for (int i = 0; i < 19; i++) {
        courant = id[i];

        if (courant != ':') {
            resultat += id[i];
        }
    }
    return resultat;
}

bool Translator::onlyNumbers(std::string valeur) {
    std::string::iterator it = valeur.begin();
    bool resultat = true;

    while (it != valeur.end()) {

        if (!isdigit(*it)) {
            resultat = false;
            break;
        }
        it++;
    }
    return resultat;
}

double Translator::formatPrix(std::string valeur) {
    double resultat = stoi(valeur);
    resultat = resultat / 100;
    return resultat;
}

void Translator::print() {

    for (std::vector<Produit*>::iterator i = produits.begin(); i != produits.end(); ++i) {
        std::cout << "ID: " << (*i)->getId() << " - " 
            << "Description: " << (*i)->getDescription() << " - " 
            << "Prix: " << (*i)->getPrix() << "$" <<std::endl;
    }
}

void Translator::write() {
    std::ofstream outfile(fichierOutput);

    for (std::vector<Produit*>::iterator i = produits.begin(); i != produits.end(); ++i) {
        outfile << formatId((*i)->getId()) << " " << (*i)->getPrix() * 100 << std::endl;
    }
    outfile.close();
}
