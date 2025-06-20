#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUITS 100
#define TAILLE_NOM 50
#define TAILLE_ID 20
#define FICHIER_SAUVEGARDE "stock.txt"

// Structure pour représenter un produit
typedef struct {
    char nom[TAILLE_NOM];
    char id[TAILLE_ID];
    int quantite;
} Produit;

// Tableau pour stocker les produits et compteur de produits
Produit stock[MAX_PRODUITS];
int nbProduits = 0;

// --- Fonctions de gestion du stock ---

// Fonction pour sauvegarder les données dans un fichier
void sauvegarderDonnees() {
    FILE *fichier = fopen(FICHIER_SAUVEGARDE, "w");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier de sauvegarde.\n");
        return;
    }
    for (int i = 0; i < nbProduits; i++) {
        fprintf(fichier, "%s;%s;%d\n", stock[i].nom, stock[i].id, stock[i].quantite);
    }
    fclose(fichier);
    printf("Donnees sauvegardees avec succes dans %s.\n", FICHIER_SAUVEGARDE);
}

// Fonction pour charger les données depuis un fichier
void chargerDonnees() {
    FILE *fichier = fopen(FICHIER_SAUVEGARDE, "r");
    if (fichier == NULL) {
        printf("Fichier de sauvegarde non trouve. Un nouveau stock sera cree.\n");
        return;
    }
    nbProduits = 0;
    while (fscanf(fichier, "%[^;];%[^;];%d\n", stock[nbProduits].nom, stock[nbProduits].id, &stock[nbProduits].quantite) == 3) {
        nbProduits++;
        if (nbProduits >= MAX_PRODUITS) {
            printf("Attention : Le nombre maximal de produits est atteint. Certains produits n'ont pas pu etre charges.\n");
            break;
        }
    }
    fclose(fichier);
    printf("%d produits charges depuis %s.\n", nbProduits, FICHIER_SAUVEGARDE);
}


// Fonction pour ajouter un nouveau produit
void ajouterProduit() {
    if (nbProduits >= MAX_PRODUITS) {
        printf("Erreur : Le stock est plein, impossible d'ajouter plus de produits.\n");
        return;
    }

    printf("\n--- Ajouter un nouveau produit ---\n");
    printf("Nom du produit : ");
    scanf("%s", stock[nbProduits].nom);
    printf("Identifiant du produit : ");
    scanf("%s", stock[nbProduits].id);
    printf("Quantite : ");
    scanf("%d", &stock[nbProduits].quantite);

    nbProduits++;
    printf("Produit ajoute avec succes !\n");
    sauvegarderDonnees(); // Sauvegarde apres chaque ajout
}

// Fonction pour modifier les details d'un produit
void modifierProduit() {
    char recherche[TAILLE_NOM];
    printf("\n--- Modifier un produit ---\n");
    printf("Entrez le nom ou l'identifiant du produit a modifier : ");
    scanf("%s", recherche);

    int trouve = 0;
    for (int i = 0; i < nbProduits; i++) {
        if (strcmp(stock[i].nom, recherche) == 0 || strcmp(stock[i].id, recherche) == 0) {
            printf("Produit trouve : Nom: %s, ID: %s, Quantite: %d\n", stock[i].nom, stock[i].id, stock[i].quantite);
            printf("Nouveau nom (laisser vide pour ne pas modifier) : ");
            char nouveauNom[TAILLE_NOM];
            scanf("%s", nouveauNom);
            if (strlen(nouveauNom) > 0) {
                strcpy(stock[i].nom, nouveauNom);
            }

            printf("Nouvel identifiant (laisser vide pour ne pas modifier) : ");
            char nouveauId[TAILLE_ID];
            scanf("%s", nouveauId);
            if (strlen(nouveauId) > 0) {
                strcpy(stock[i].id, nouveauId);
            }

            printf("Nouvelle quantite (-1 pour ne pas modifier) : ");
            int nouvelleQuantite;
            scanf("%d", &nouvelleQuantite);
            if (nouvelleQuantite != -1) {
                stock[i].quantite = nouvelleQuantite;
            }

            printf("Produit modifie avec succes !\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Produit non trouve.\n");
    }
    sauvegarderDonnees(); // Sauvegarde apres chaque modification
}

// Fonction pour supprimer un produit
void supprimerProduit() {
    char recherche[TAILLE_NOM];
    printf("\n--- Supprimer un produit ---\n");
    printf("Entrez le nom ou l'identifiant du produit a supprimer : ");
    scanf("%s", recherche);

    int trouve = 0;
    for (int i = 0; i < nbProduits; i++) {
        if (strcmp(stock[i].nom, recherche) == 0 || strcmp(stock[i].id, recherche) == 0) {
            // Decaler les elements suivants pour "supprimer" le produit
            for (int j = i; j < nbProduits - 1; j++) {
                stock[j] = stock[j + 1];
            }
            nbProduits--;
            printf("Produit supprime avec succes !\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Produit non trouve.\n");
    }
    sauvegarderDonnees(); // Sauvegarde apres chaque suppression
}

// Fonction pour afficher la liste de tous les produits
void afficherProduits() {
    printf("\n--- Liste des produits en stock ---\n");
    if (nbProduits == 0) {
        printf("Le stock est vide.\n");
        return;
    }
    printf("%-20s %-15s %-10s\n", "Nom", "Identifiant", "Quantite");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < nbProduits; i++) {
        printf("%-20s %-15s %-10d\n", stock[i].nom, stock[i].id, stock[i].quantite);
    }
}

// Fonction pour rechercher un produit par nom ou identifiant
void rechercherProduit() {
    char recherche[TAILLE_NOM];
    printf("\n--- Rechercher un produit ---\n");
    printf("Entrez le nom ou l'identifiant du produit a rechercher : ");
    scanf("%s", recherche);

    int trouve = 0;
    for (int i = 0; i < nbProduits; i++) {
        if (strcmp(stock[i].nom, recherche) == 0 || strcmp(stock[i].id, recherche) == 0) {
            printf("Produit trouve : Nom: %s, ID: %s, Quantite: %d\n", stock[i].nom, stock[i].id, stock[i].quantite);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Produit non trouve.\n");
    }
}

// --- Fonction principale ---

int main() {
    chargerDonnees(); // Charger les donnees au demarrage

    int choix;
    do {
        printf("\n--- Menu Gestion de Stock ---\n");
        printf("1. Ajouter un nouveau produit\n");
        printf("2. Modifier les details d'un produit\n");
        printf("3. Supprimer un produit\n");
        printf("4. Afficher la liste des produits\n");
        printf("5. Rechercher un produit\n");
        printf("6. Sauvegarder les donnees\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterProduit();
                break;
            case 2:
                modifierProduit();
                break;
            case 3:
                supprimerProduit();
                break;
            case 4:
                afficherProduits();
                break;
            case 5:
                rechercherProduit();
                break;
            case 6:
                sauvegarderDonnees();
                break;
            case 0:
                printf("Merci d'avoir utilise le systeme de gestion de stock. Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}