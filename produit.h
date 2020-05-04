#ifndef __PRODUIT_H__
#define __PRODUIT_H__
#include <string>

//!  Classe publique qui definit un Produit
/*!
  Classe publique definissant un Produit
*/
class Produit
{
    private:
        //! Variable privee
        /*!
          Donnee de type string representant le ID d'un Produit
        */
        std::string id;

        //! Variable privee
        /*!
          Donnee de type string la description d'un Produit
        */
        std::string description;

        //! Variable privee
        /*!
          Donnee de type double representant le prix d'un produit
        */
        double prix;
    public:
        //! Constructeur publique
        /*!
          Le Constructeur publique permet de creer un objet de type Produit.
          Initialise tous les attributs vides.
        */
        Produit();

        //! Constructeur
        /*!
          Le Constructeur permet de creer un objet de type Produit
          \param id Donnee de type std:string representant le ID d'un Produit
          \param nom Donnee de type std:string representant la description d'un Produit
          \param prix Donnee de type double representant le prix d'un Produit
        */
        Produit(std::string id, std::string description, double prix);

        //! Destructeur publique par defaut
        /*!
          Le Destructeur publique par defaut.
          Prend en charge la destruction du Produit
        */
        ~Produit();

        //! Methode publique
        /*!
          Cette methode permet d'obtenir le ID d'un Produit
          \return Donnee de type std::string representant le ID d'un Produit
        */
        std::string getId() const;

        //! Methode publique
        /*!
          Cette methode permet d'obtenir la description d'un Produit
          \return Donnee de type std::string representant la description d'un Produit
        */
        std::string getDescription() const;

        //! Methode publique
        /*!
          Cette methode permet d'obtenir le ID d'un Produit
          \return Donnee de type double representant le prix d'un Produit
        */
        double getPrix() const;
};
#endif //__PRODUIT_H__
