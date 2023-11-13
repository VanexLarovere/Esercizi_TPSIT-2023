#include <stdio.h>
#include <stdlib.h>

int main() {
    int dim;
    
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &dim);

    int *vet = (int *)malloc(dim * sizeof(int)); // Allocazione dinamica dell'array di interi

    printf("Inserisci %d valori interi:\n", dim);
    for (int i = 0; i < dim; i++) {
        scanf("%d", &vet[i]);
    }

    printf("Valori inseriti:\n");
    for (int i = 0; i < dim; i++) {
        printf("%d ", vet[i]);
    }

    free(vet);

    return 0;
}
