#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition des structures de données
typedef struct {
    char nom[50];
    char type[10];
} Champ;

typedef struct {
    char** valeurs;
} Enregistrement;

typedef struct {
    char nom[50];
    Champ* champs;
    int nombre_champs;
    Enregistrement* enregistrements;
    int nombre_enregistrements;
} Table;

Table* tables[10]; // Support pour jusqu'à 10 tables
int nombre_tables = 0;

// Fonction pour créer une table
void creer_table(char* nom, Champ* champs, int nombre_champs) {
    Table* table = (Table*)malloc(sizeof(Table));
    strcpy(table->nom, nom);
    table->champs = (Champ*)malloc(nombre_champs * sizeof(Champ));
    memcpy(table->champs, champs, nombre_champs * sizeof(Champ));
    table->nombre_champs = nombre_champs;
    table->enregistrements = NULL;
    table->nombre_enregistrements = 0;
    tables[nombre_tables++] = table;
    printf("Table '%s' créée.\n", nom);
}

