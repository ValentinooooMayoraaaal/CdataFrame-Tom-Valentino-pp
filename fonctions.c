//
// Created by tombo on 27/03/2024.
//
Column *create_column(char *title) {
    Column *colonne = malloc(sizeof(Column));

    colonne->titre = strdup(title);
    colonne->donnees = NULL; // pointeur sur le tableau
    colonne->taille_physique = 256;
    colonne->taille_logique = 0;

    return colonne;
}