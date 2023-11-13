#include <stdio.h>
#include <stdlib.h>
#define DIM 100

typedef struct{
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct{
    char cognome[DIM];
    char nome[DIM];
    Data data;
} Persona;

int inizializzaFile(Persona persone[], int max, char* campo){
    FILE *fp;
    int* p;
    fp = fopen("EsercizioSintesi1.csv", "r");
    if(fp == NULL){
        printf("Errore nell'apertura del file");
        exit(1);
    }

    while(fgets(fp, "%s %s %d %d %d", persone[k].cognome, persone[k].nome, persone[k].data.giorno, 
            persone[k].data.mese, persone[k].data.anno)){
        campo = strtok (riga, ",");
        (persone + k)->cognome = strdup(campo);

        campo = strtok (NULL, ",");
        (persone + k)->nome = strdup(campo);

        campo = strtok (NULL, ",");
        (persone + k)->data.giorno = atof(campo);

        campo = strtok (NULL, ",");
        (persone + k)->data.mese = atof(campo);

        campo = strtok (NULL, ",");
        (persone + k)->data.anno = atof(campo);

        k++;
    }
    p = (Persona*) malloc(k * sizeof(Persona));
    fclose(fp);
    return k;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordinamento(Persona persone[], int n){ 
    int sup, sca;  
    sup = n - 1; 
    while (sup > 0) { 
        sca = 0; 
        for (int *p = persone; p < persone + sup; p++) { 
            if (*p < *(p + 1)){ 
                swap(p, p + 1); 
                sca = p - persone; 
            } 
        } 
        sup = sca; 
     } 
 } 


void stampaDecrescente(Persona persone[], int n){
    ordinamento(persone, n);
    printf("Ordinato dal più grande al più piccolo: \n");
    for(int *p=persone; p<vett+n; p++){
        printf("%s %s %d %d %d\n", persone[k].cognome, persone[k].nome, persone[k].data.giorno, 
        persone[k].data.mese, persone[k].data.anno);
    }
}

int main(){
    Persona persone[DIM];
    char* campo;
    char riga[DIM];
    k = inizializzaFile(persone, DIM, campo);

    stampaDecrescente(persone, k);

    return 0;
}