#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct {
    int number;
    char* title;
    char* type;
    int year;
    char* state;
} Film;

int caricaFile(Film videoteca[], char* fileName, char* campo, char* riga) {
    FILE* fp;
    fp = fopen(fileName, "r");
    int k = 0;

    if(fp == NULL) {
        printf("Il file %s non esiste o e' vuoto!\n", fileName);
        exit(1);
    }

    while(fgets(riga, LUNG_RIGA, fp)) { //se incontra EOF diventa false ed esce
        campo = strtok (riga,",");
        videoteca[k].number = atoi(campo); //atoi passa da stringa e int con atof da stringa a float

        campo = strtok (NULL,",");
        videoteca[k].title = strdup(campo);

        campo = strtok (NULL,",");
        videoteca[k].type = strdup(campo);

        campo = strtok (NULL,",");
        videoteca[k].year = atoi(campo);

        campo = strtok (NULL,",");
        videoteca[k].state = strdup(campo);

        k++;
        }
        fclose(fp); //chiude il file
    return k;
}

void stampaFilm(Film videoteca[], int dim) {
    for(int k = 0; k < dim; k++) {
        printf("\n%d %s %s %d %s", videoteca[k].number, videoteca[k].title, videoteca[k].type, videoteca[k].year, videoteca[k].state);
    }
}

int main() {
    Film videoteca[NUM_RIGHE];
    char fileName[] = "listaFilmConVirgole.csv";
    char riga[LUNG_RIGA];
    char* campo;
    int dim;

    dim = caricaFile(videoteca, fileName, campo, riga);

    stampaFilm(videoteca, dim);

    return 0;
}
