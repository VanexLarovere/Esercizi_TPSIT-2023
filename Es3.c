#include <stdio.h>
#include <stdlib.h>
#define DIM 10
/*
Scrivere un programma in C che calcoli la somma degli
elementi di un array utilizzando l'aritmetica dei puntatori. Nel programma deve
essere implementata una funzione calcolaSomma()
che riceva due argomenti (la lunghezza dell'array e un puntatore), calcola la
somma degli elementi dell'array utilizzando un puntatore e
restituisce la somma calcolata. Il main()
dichiara un array, utilizza la funzione calcolaSomma() e stampa il risultato
restituito dalla funzione.*/

int calcolaSomma(int* vet, int n){
    int somma;
    for(int k=0; k<n; k++){
        somma += *(vet + k);
    }
    return somma;
}

void riempiVet(int* vet, int n){
    for(int k=0; k<n; k++){
        printf("Inserisci il valore in posizione %d: ", k);
        scanf("%d", (vet + k));
    }
}

int main(){
    int* vet;
    int somma;
    riempiVet(vet, DIM);
    somma = calcolaSomma(vet, DIM);
    printf("La somma e' : %d", somma);

    return 0;
}