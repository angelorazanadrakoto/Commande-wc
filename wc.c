#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <nom_fichier>\n", argv[0]);
        return 1;
    }

    FILE *fichier = fopen(argv[1], "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    int mots = 0, lignes = 0, caracteres = 0;
    char c;
    int estDansUnMot = 0;

    while ((c = fgetc(fichier)) != EOF) {
        caracteres++;

        if (c == '\n') {
            lignes++;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            estDansUnMot = 0;
        } else if (estDansUnMot == 0) {
            estDansUnMot = 1;
            mots++;
        }
    }

    fclose(fichier);

    printf("Mots: %d\n", mots);
    printf("Lignes: %d\n", lignes);
    printf("Caracteres: %d\n", caracteres);

    return 0;
}