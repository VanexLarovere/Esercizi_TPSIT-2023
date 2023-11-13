#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct {
    int numero;
    char* titolo[DIM_RIGA];
    char* genere[DIM_RIGA];
    int anno;
    char* disponibilita[DIM_RIGA];
} Film;

int main(){
    char filename[] = "listafilm.csv";
    char riga[DIM_RIGA];
    FILE *fp;
    char* campo;
    film array_film[NUM_RIGHE];
    int counter = 0;

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Il file %s non esiste\n", filename);
        exit(1); //interrompe il programma e ritorna 1
    }
    //fgets(riga, DIM_RIGA, fp)
    while(fgets(fp, "%d %s %s %s %s", &film[k].nfilm, film[k].nomefilm, film[k].genere, film[k].data, film[k].disponibilita)){
        campo = strtok(riga, ",");
        array_film{counter}.numero = atoi(campo); //Converte un numero in intero, da stringa a float atof

        campo = strtok(NULL, ",");
        array_film{counter}.titolo= strdup(campo); //Duplica

        campo = strtok(NULL, ",");
        array_film(counter).genere = strdup(campo);


        counter++;
    }


    return 0;
}
