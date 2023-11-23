//Fare una funzione nel main che calcola la lunghezza della lista 
//Chiedere all'utente un numero intero ed aggiungerlo alla fine della lista
//Aggiungi elemento inizio e cancella ultimo elemento
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int valore;
    struct nome* next;
}Node;

void aggiungiNumeroFine(Node** lista, int num){
    Node* l = *lista;
    do{        
        l = l->next;
    }while(l->next != NULL);
    
    l->next = (Node*) malloc(sizeof(Node));
    l = l->next;
    l->valore = num;
    l->next = NULL;
}

int calcolaLunghezza(Node* lista){
    Node* l = lista;
    int lung = 0;
    while(l != NULL){
        lung++;
        l = l->next;
    }
    return lung;
}

int ricorsivaLunghezza(Node** lista, int lung){
    Node* l = lista;
    int lung = 0;
    if(l != NULL){
        lung++;
        lung = ricorsivaLunghezza(l->next, lung);
    }
    return lung;
}

void stampaListaRicorsiva(Node* lista){
    Node* l = lista;
    if(l != NULL){
        printf("%d", l->valore);
        stampaListaRicorsiva(l->next);
    }
}

int contaElementiRicorsivo(Node* lista){
    if(lista->next != NULL){
        return 1 + contaElementiRicorsivo(lista->next);
    }
    return 1;
}


int main(){
    int n;
    int lung = 0;
    int num;
    Node* lista = NULL;
    Node* l;
    do{
        printf("Inserisci un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            } else {
                l->next = (Node*) malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n >= 0);

    l = lista;
    printf("numeri inseriti: ");
    printf("\n");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }
    printf("\n");
    printf("Numero di elementi: %d", calcolaLunghezza(lista));
    printf("\nNumero di elementi con ricorsiva: %d", ricorsivaLunghezza(lista, lung));
    stampaLista(lista);
    printf("\nValori lista ricorsiva: ");
    stampaListaRicorsiva(lista);
    printf("\nInserisci un valore intero: ");
    scanf("%d", &num);
    aggiungiNumeroFine(lista, num);
    return 0;
}