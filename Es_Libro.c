#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 100
/*
author: Vanessa Larovere
date: 29/10/2023
es: 005
text:
Scrivi un programma in linguaggio C che
gestisca un archivio di libri. Il programma deve utilizzare una struttura Libro per rappresentare ciascun libro, con le seguenti
informazioni:
-title (massimo 100 caratteri)
-author (massimo 100 caratteri)
-Anno di pubblicazione
Il programma deve consentire all'utente
di eseguire le seguenti operazioni:
Stampare l'archivio dei libri:
-Stampa tutte le informazioni sui libri presenti nell'archivio.
-Stampa l’archivio dei libri pubblicati in un certo anno.
-Stampa tutti i libri pubblicati in ordine di anno.
Assicurati che il programma gestisca
correttamente la memoria dinamica e che non ci siano perdite di memoria.
Inoltre, gestisci eventuali errori nell'apertura del file CSV.
Ricorda di fornire un'interfaccia utente
chiara e intuitiva per consentire all'utente di eseguire queste operazioni.
*/

typedef struct{
    char title[MAX_CHAR];
    char author[MAX_CHAR];
    int anno;
} Libro;

void swap()

void bubbleSort(Libro* archivio, int n){
    int sup, sca;
    sup = n-1;
    while(sup > 0){
        sca = 0;
        for(Libro* p = archivio, p < archivio + n; p++){
            if(p->anno < (p+1)->anno){
                swap(p->anno, (p+1)->anno);
            }
        }
    }
}

int contaLibri(char nomeFile[]){
    FILE* fp;
    char c;
    int cont = 0;
    fp = fopen(nomeFile, "r");
    if(fp == NULL){
        printf("Errore nell'apertura del file");
    }
    else{
        while((c = fgetc(fp)) != EOF){
            if(c == '\n'){
                cont++;
            }
        }
    }
    fclose(fp);
    return cont;
}

void caricaLibri(Libro* archivio, char nomeFile[], int n){
    FILE* fp;
    fp = fopen(nomeFile, "r");
    char riga[MAX_CHAR];
    char* campo;
    if(fp == NULL){
        printf("Errore nell'apertura del file");
    }
    else{
        for(Libro* p = archivio; p< archivio + n; p++){
            fgets(riga, MAX_CHAR, fp);

            campo = strtok(riga, ",");

            campo = strtok(NULL, ",");
            p->author = strdup(campo);

            campo = strtok(NULL, ",");
            p->title = strdup(campo);

            campo = strtok(NULL, ",");
            p->anno = atoi(campo);
        }
        fclose(fp);
    }
}

int main(){
    Libro* archivio;
    char nomeFile[MAX_CHAR];
    int n_libri;
    n_libri = contaLibri(nomeFile);

    archivio = (Libro*) malloc(n_libri * sizeof(Libro*));

    caricaLibri(archivio, nomeFile, n_libri);
    free(archivio);

    return 0;
}