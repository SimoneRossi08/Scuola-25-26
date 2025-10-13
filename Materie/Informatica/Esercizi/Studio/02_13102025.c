/* Esempio di malloc e realloc insieme
    Scrivere un programma in linguaggio C che:
    1. Allochi dinamicamente un array iniziale di n numeri interi con malloc;
    2. inserimento dei valori;
    3. stampi l'array;
    4. calcoli la somma dei valori multipli di 3;
    5. creiamo un nuovo array con solo i numeri dispari
*/

#include <stdio.h>
#include <stdlib.h>

int alloc(int* array, int *dim);
int addval(int* array, int *dim);
void stampa(int* array, int *dim);

int main(){

    int* array;
    int opt;
    int *dim;

    printf("-----MENU-----");
    scanf("%d", &opt);
    switch(opt){
    case 1:
            alloc(array, dim);
        break;
    case 2:
            addval(array, dim);
        break;
    case 3:
            stampa(array,dim);
        break;
    default:
    printf("\nErrore! Opzione inesistente.");
        break;
    }

}

int alloc(int* array, int *dim){

    printf("\nInserire la dimensione:");
    scanf("%d", dim);

    *array=(int*)malloc((*dim)*sizeof(int));

    return *array;
}

int addval(int* array, int *dim){

    int n;

    for(int i=0; i<dim; i++){
        printf("\nInserisci un numero: ");
        scanf("%d", &n);
        *array[i]=n;
    }

    return *array;
}

void stampa(int* array, int *dim){

    for(int i=0; i<dim; i++){
        printf("%d\t", *array[i]);
    }
}