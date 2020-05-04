#ifndef __TRANSLATOR_H__
#define __TRANSLATOR_H__
#include <fstream>
#include <vector>
#include "produit.h"

//!  Classe publique qui definit un Traducteur
/*!
  Classe publique qui traduit un fichier de input de type FACTURATOR en fichier de output de type DACOUNT
*/
class Translator
{
    private:
        //! Variable privee
        /*!
          Donnee de type string.
          Represente le nom du fichier de input
        */
        std::string fichierInput;

        //! Variable privee
        /*!
          Donnee de type string.
          Represente le nom du fichier de output
        */
        std::string fichierOutput;

        //! Variable privee
        /*!
          Vector de type Produit*.
          Contient des pointeurs vers les produits recuperes dans le input file
        */
        std::vector<Produit*> produits;

    public:
        //! Constructeur pour un traducteur
        /*!
          Le Constructeur publique de Translator
          \param fichierInput Donnee de type std:string representant le nom du fichier de input
          \param fichierOutput Donnee de type std:string representant le nom du fichier de output
        */
        Translator(std::string fichierInput, std::string fichierOutput);

        //! Destructeur publique par defaut
        /*!
          Le Destructeur publique par defaut.  Prend en charge la destruction de cette classe
        */
        ~Translator();

        //! Methode publique
        /*!
          Cette methode extrait les produits du input file afin de remplir le Vector
        */
        void extract();

        //! Methode publique
        /*!
          Cette methode retire les ":" du ID d'un produit
          \param id Donnee de type std:string representant ID a formatter
          \return Valeur de type double representant le ID sans les ":"
        */
        std::string formatId(std::string id);

        //! Methode publique
        /*!
          Cette methode verifie si un string contient seulement des numbers
          \param valeur Donnee de type std:string representant la string a verifier
          \return True si la string contient seulement des numeros. Sinon False.
        */
        bool onlyNumbers(std::string valeur);

        //! Methode publique
        /*!
          Cette methode formatte le prix en format double afin de storer dans un objet de type Produit
          \param valeur Donnee de type std:string representant le prix a convertir
          \return Valeur de type double representant le prix dans le bon format
        */
        double formatPrix(std::string valeur);

        //! Methode publique
        /*!
          Cette methode affiche le contenu de Vector de Produits
        */
        void print();

        //! Methode publique
        /*!
          Cette methode ecrit les produits contenus dans le Vector dans le fichier de output
        */
        void write();
};
#endif //__TRANSLATOR_H__
