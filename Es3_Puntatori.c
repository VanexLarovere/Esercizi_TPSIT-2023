#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LUNG_RIGA 200
#define NUM_RIGHE 20000
#define FILM 31
#define STRL 31

/*
author: Vanessa Larovere
date: 16/10/2023
es: Es3_puntatori
text: La videoteca "Ciak film" necessita di un programma che carichi la lista film in un array di struttura e che stampi a video i 5
campi : numero, titolo film, genere, anno di uscita, disponibilità film

con puntatori + funzione contarighe che conta quante righe ha l'array con malloc
*/

typedef struct {
    int number;
    char* title; //char tittle[STRL];
    char* type;
    int year;
    char* state;
} Film;

int caricaFile(Film videoteca[], char* fileName, char* campo, char* riga, int nrighe) {
    FILE* fp;
    fp = fopen(fileName, "r");
    int* p;

    if(fp == NULL) {
        printf("Il file %s non esiste o e' vuoto!\n", fileName);
        exit(1);   
    }

    while(fgets(riga, LUNG_RIGA, fp)) { //se incontra EOF diventa false ed esce
        campo = strtok (riga,",");
        //(*(videoteca + k)).number = atoi(campo); //più pesante e scomoda, meglio la seguente
        (videoteca + k)->number = atoi(campo); //atoi passa da stringa e int con atof da stringa a float

        campo = strtok (NULL,",");
        (videoteca + k)->title = strdup(campo); //strdup duplica il campo

        campo = strtok (NULL,",");
        (videoteca + k)->type = strdup(campo);

        campo = strtok (NULL,",");
        (videoteca + k)->year = atoi(campo);

        campo = strtok (NULL,",");
        (videoteca + k)->state = strdup(campo);
        
        p = (Film*) malloc(nrighe * sizeof(Film))
        }
        fclose(fp); //chiude il file
    return k;
}

void stampaFilm(Film videoteca[], int dim) {
    for(int k = 0; k < dim; k++) {
        printf("\n%d %s %s %d %s", (videoteca + k)->number, (videoteca + k)->title, (videoteca + k)->type, (videoteca + k)->year, (videoteca + k)->state);
    }
}

void contarighe(char filename[], Film videoteca[], int max){
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Errore con l'apertura del file");
    }
    else{
        while(fgets(riga, LUNG_RIGA, fp)){
            k++;
        }
    }
    fclose(fp);
    return k;
}

int main() {
    Film videoteca[NUM_RIGHE];
    char fileName[] = "listaFilmConVirgole.csv";
    char riga[LUNG_RIGA];
    char* campo;
    int dim;
    int nrighe

    nrighe = contarighe(filename, videoteca, NUM_RIGHE);

    caricaFile(videoteca, fileName, campo, riga, nrighe);

    stampaFilm(videoteca, dim);

    return 0;
}