# GESTION-DE-STOCK-AVEC-C

## Introduction

Ce projet est un système de gestion de stock basique développé en langage C. Il permet de gérer des produits en stock en réalisant des opérations courantes telles que l'ajout, la modification, la suppression, l'affichage et la recherche de produits. Les données du stock sont sauvegardées automatiquement dans un fichier texte pour assurer leur persistance entre les sessions.

Ce programme est idéal pour une première approche de la gestion de données et des opérations sur fichiers en C.

## Fonctionnalités

Le système offre les fonctionnalités suivantes :

* **Ajouter un nouveau produit** : Enregistrer un nouveau produit avec son nom, son identifiant unique et sa quantité.
* **Modifier les détails d'un produit** : Mettre à jour le nom, l'identifiant ou la quantité d'un produit existant.
* **Supprimer un produit** : Retirer un produit du stock.
* **Afficher la liste des produits** : Voir tous les produits actuellement en stock, avec leurs détails.
* **Rechercher un produit** : Trouver un produit spécifique par son nom ou son identifiant.
* **Sauvegarder les données** : Les données sont automatiquement sauvegardées dans un fichier texte (`stock.txt`) après chaque modification (ajout, suppression, modification) et chargées au démarrage du programme.

---

## Comment Compiler et Exécuter

Ce projet est conçu pour être compilé avec **Dev-C++**, mais il peut être compilé avec n'importe quel compilateur C standard (comme GCC).

### Avec Dev-C++

1.  **Ouvrez Dev-C++**.
2.  **Créez un nouveau projet de type "Console Application"** (Fichier -> Nouveau -> Projet -> Console Application).
3.  **Copiez le code source** fourni dans le fichier `main.c` (ou le nom que vous avez donné à votre fichier source).
4.  **Compilez le projet** (Exécuter -> Compiler ou appuyez sur `F9`).
5.  **Exécutez le programme** (Exécuter -> Exécuter ou appuyez sur `F10`).

## Persistance des Données

Les données de votre stock sont sauvegardées dans un fichier nommé `stock.txt`. Ce fichier sera créé dans le **même répertoire** que l'exécutable du programme (`.exe` sur Windows). Si vous déplacez l'exécutable, le fichier `stock.txt` devra être déplacé avec lui pour que le programme retrouve vos données.

---

## Structure du Code

Le code est organisé de manière modulaire avec des fonctions dédiées à chaque tâche :

* `Produit` (structure) : Définit la structure d'un produit.
* `stock` (tableau) et `nbProduits` (entier) : Gèrent les produits en mémoire.
* `sauvegarderDonnees()` : Écrit les produits dans `stock.txt`.
* `chargerDonnees()` : Lit les produits depuis `stock.txt`.
* `ajouterProduit()` : Ajoute un nouveau produit au stock.
* `modifierProduit()` : Modifie les détails d'un produit existant.
* `supprimerProduit()` : Supprime un produit du stock.
* `afficherProduits()` : Affiche tous les produits en stock.
* `rechercherProduit()` : Recherche un produit par nom ou identifiant.
* `main()` : Le point d'entrée du programme, gère le menu interactif.

---

## Limitations Actuelles

* Le nombre maximal de produits est fixé à `MAX_PRODUITS` (actuellement 100).
* La recherche et la modification se basent sur une correspondance exacte du nom ou de l'identifiant.
* La gestion des erreurs de saisie (par exemple, entrer du texte au lieu d'un nombre pour la quantité) est basique.

