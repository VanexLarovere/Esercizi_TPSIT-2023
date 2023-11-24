//Fare una funzione nel main che calcola la lunghezza della lista
//Chiedere all'utente un numero intero ed aggiungerlo alla fine della lista
//Aggiungi elemento inizio e cancella ultimo elemento
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valore;
    struct node* next;
} Node;

void aggiungiNumeroFine(Node** lista, int num) {
    Node* l = *lista;

    //Verifico se la lista è vuota
    if (l == NULL) {
        *lista = (Node*)malloc(sizeof(Node));
        l = *lista;
    } else {
        //Trovo l'ultimo elemento della lista
        while (l->next != NULL) {
            l = l->next;
        }
        //Alloco una nuova cella
        l->next = (Node*)malloc(sizeof(Node));
        l = l->next;
    }

    l->valore = num;
    l->next = NULL;
}

int calcolaLunghezza(Node* lista) {
    Node* l = lista;
    int lung = 0;
    while (l != NULL) {
        lung++;
        l = l->next;
    }
    return lung;
}

int ricorsivaLunghezza(Node* lista) {
    if (lista == NULL) {
        return 0;
    } else {
        return 1 + ricorsivaLunghezza(lista->next);
    }
}

void stampaListaRicorsiva(Node* lista) {
    Node* l = lista;
    if (l != NULL) {
        printf("%d ", l->valore);
        stampaListaRicorsiva(l->next);
    }
}

int contaElementiRicorsivo(Node* lista) {
    if (lista->next != NULL) {
        return 1 + contaElementiRicorsivo(lista->next);
    }
    return 1;
}

int main() {
    int n;
    int num;
    Node* lista = NULL;

    do {
        printf("Inserisci un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if (n >= 0) {
            aggiungiNumeroFine(&lista, n);
        }
    } while (n >= 0);

    l = lista;
    printf("Numeri inseriti:\n");
    while (l != NULL) {
        printf("%d - %p\n", l->valore, (void*)l->next);
        l = l->next;
    }

    printf("\nNumero di elementi: %d", calcolaLunghezza(lista));
    printf("\nNumero di elementi con ricorsiva: %d", ricorsivaLunghezza(lista));
    printf("\nValori lista ricorsiva: ");
    stampaListaRicorsiva(lista);

    printf("\nInserisci un valore intero: ");
    scanf("%d", &num);
    aggiungiNumeroFine(&lista, num);

    return 0;
}
