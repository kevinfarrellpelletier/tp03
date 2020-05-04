#include "produit.h"

Produit::Produit() {
    id = "";
    description = "";
    prix = 0;
}

Produit::Produit(std::string id, std::string description, double prix) {
    this->id = id;
    this->description = description;
    this->prix = prix;
}

Produit::~Produit() {}

std::string Produit::getId() const {
    return id;
}

std::string Produit::getDescription() const {

    if (description != "") {
        return description;
    }
    else {
        return "Description Vide";
    }
}

double Produit::getPrix() const {
    return prix;
}