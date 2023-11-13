#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100

typedef struct {
    int nfilm;
    char *nomefile;
    char *genere;
    int data;
    char *disponibilita;
} Film;

int leggiFilm(Film *(film), int n){
    FILE *fp;
    int k=0;
    char *nomefile;
    char campo;
    do{
    printf("Inserisci il nome del file contenenti le informazioni: ");
    fflush(stdin);
    gets(nomefile);
    fp = fopen(nomefile, "r");
    }while(fp == NULL);

    while(fgets(k, DIM, fp) != EOF) { //se incontra EOF diventa false ed esce
        campo = strtok (k,",");
        (film + k)->nfilm = atoi(campo); //atoi passa da stringa e int con atof da stringa a float

        campo = strtok (NULL,",");
        (film + k)->nomefilm = strdup(campo); //strdup duplica il campo

        campo = strtok (NULL,",");
        (film + k)->genere = strdup(campo);

        campo = strtok (NULL,",");
        (film + k)->data = atoi(campo);

        campo = strtok (NULL,",");
        (film + k)->disponibilita = strdup(campo);

        k++;
    }
    fclose(fp);
    return k;
}

void stampaFilm(Film *(film), int n, int anno){
    for(int k=0; k<n; k++){
        if(*(film +k).data == anno){
            printf("%d %s %s %s %s\n", &(film +k).nfilm, &(film +k).nomefilm, &(film +k).genere, &(film +k).data, &(film +k).disponibilita);
        }
    }
}

int main(){
    Film (film +DIM);
    int k, anno;
    printf("Inserisci l'anno di uscita dei film che vuoi vedere: ");
    scanf("%d", &anno);
    k = leggiFilm(film, DIM);
    stampaFilm(film, k, anno);

    return 0;
}
