Guide d'Utilisation du Logiciel de Manipulation de Dataframe
Ce guide vous explique comment utiliser les différentes fonctions disponibles pour manipuler et trier des dataframes à l'aide de votre logiciel.

Préparation
Assurez-vous d'avoir les fichiers suivants dans le même répertoire :

sort.c
cdataframe.c
column.c
cdataframe.h
column.h
sort.h
Compilez votre programme avec la commande suivante :
gcc -o my_program sort.c cdataframe.c column.c -I.

Utilisation
Création et Remplissage d'un Dataframe

Créer un Dataframe Vide
CDataframe *dataframe = create_dataframe();

Remplir un Dataframe en Interactif
remplir_dataframe(dataframe);

Remplir un Dataframe avec des Données en Dur
remplir_dataframe_en_dur(dataframe);


Affichage du Dataframe:

Afficher Tout le Dataframe
afficher_dataframe(dataframe);

Afficher une Partie du Dataframe (Par Lignes)
afficher_dataframe_partiel_ligne(dataframe);

Afficher une Partie du Dataframe (Par Colonnes)
afficher_dataframe_partiel_colonne(dataframe);


Modification du Dataframe:

Ajouter une Ligne au Dataframe
int nouvelle_ligne[] = {val1, val2, val3}; // Remplacez val1, val2, val3 par vos valeurs
ajouter_ligne_Cdataframe(dataframe, nouvelle_ligne);

Supprimer une Ligne du Dataframe
int indice_ligne = 2; // Indice de la ligne à supprimer
supprimer_ligne(dataframe, indice_ligne);

Ajouter une Colonne au Dataframe

int indice_colonne = 1; // Indice où ajouter la colonne
char *titre = "Nouvelle Colonne";
ajouter_colonne(dataframe, indice_colonne, titre);

Supprimer une Colonne du Dataframe
int indice_colonne = 1; // Indice de la colonne à supprimer
supprime_colonne_du_dataframe(dataframe, indice_colonne);

Renommer une Colonne
int indice_colonne = 1; // Indice de la colonne à renommer
char *nouveau_titre = "Titre Modifié";
renommer_colonne(dataframe, indice_colonne, nouveau_titre);

Modifier la Valeur d'une Cellule
int indice_ligne = 2;
int indice_colonne = 1;
int nouvelle_valeur = 42;
modifier_valeur_cellule(dataframe, indice_ligne, indice_colonne, nouvelle_valeur);

Tri des Colonnes:


Choisir une Colonne à Trier
int col_index = choice_column(dataframe);

Choisir la Direction du Tri
int direction = choice_dir();

Trier une Colonne
COLUMN *colonne = dataframe->colonnes[col_index];
sort(colonne, direction);


Recherche et Statistiques:

Afficher les Noms des Colonnes
afficher_noms_colonnes(dataframe);

Nombre de Colonnes dans le Dataframe
int nb_colonnes = print_number_column(dataframe);

Nombre de Lignes dans le Dataframe
int nb_lignes = nombre_lignes(dataframe);


Vérifier l'Existence d'une Valeur
int valeur = 42;
bool existe = check_value_existing(dataframe, valeur);

Occurence d'une Valeur
occurence_x_in_dataframe(dataframe);

Occurences des Valeurs Supérieures à x
occurence_number_sup_to_x_in_dataframe(dataframe);

Occurences des Valeurs Inférieures à x
occurence_number_inf_to_x_in_dataframe(dataframe);

Recherche d'une Valeur dans une Colonne Triée
int valeur_recherchee = 42;
int resultat = search_value_in_column(colonne, &valeur_recherchee);


Exécution du Programme.
Pour exécuter le programme compilé :

sh
Copier le code
./my_program
Cela lancera votre programme et vous pourrez suivre les instructions à l'écran pour manipuler le dataframe.
