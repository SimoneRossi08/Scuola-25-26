/* Scrivi un programma in C che: 
    1. Chiede all'utente quanti numeri interi vuole inserire.
    2. Alloca dinamicamente un array di quella dimensione con malloc().
    3. Permette all'utente di inserire i numeri.
    4. Chiede all'utente se vuole aumentare la dimensione del'array:
        - Se sì, richiede la nuova dimensione e usa realloc() per ridimensionarlo.
        - Permette quindi di inserire i nuovi valori negli spazi aggiunti.
    5. Infine, stampa tutti gli elementi dell'array.
*/

#include <stdio.h>
#include <stdlib.h>

int* creaarray(int _n, int *_array){

    _array=(int*)malloc(_n *sizeof(int));

    if(_array==NULL){
        printf("Errore di allocazione!\n");
        return NULL;
    }

    return _array;
}

int* insarray(int *_array, int _n){

    for(int i=0; i<_n; i++){
        printf("Inserisci un elemento: ");
        scanf("%d", &_array[i]);
    }
    
    return _array;
}

void stampaarray(int *_array, int _n){

    for(int i=0; i<_n; i++){
        printf("%d ", _array[i]);
    }
    printf("\n");
}

int* aumendim(int *_array, int _n){
    
    int d;
    int* tmp=NULL;

    do{
        printf("Inserisci la nuova dimensione dell'array: ");
        scanf("%d", &d);
    }
    while(d<0);

    tmp=(int*)realloc(_array, (d)*sizeof(int));
    if(tmp==NULL){
        printf("Errore di allocazione!\n");
        free(_array);
        return NULL;
    }
    _array=tmp;

    if(_n<d){
        for(int i=_n; i<d; i++){
            printf("Inserisci un nuovo elemento:");
            scanf("%d", &_array[i]);
        }
        _n=d;
    }

    return _array;
}

int main(){

    int opt, n,*array=NULL;

    do{
        printf("Inserisci la quantità di elementi: ");
        scanf("%d", &n);
    }
    while(n<0);

    creaarray(array, n);
    insarray(array, n);

    printf("Cosa vuoi fare con l'attuale array?\n");
    printf("1. Aumentare la sua dimensione.\n");
    printf("2. Mantenerlo uguale.\n");
    scanf("%d", &opt);

    do{
        switch(opt){
        case 1:
                array=aumendim(array, n);
            break;
              
        case 2:
                
            break;

        default:
            printf("Errore! Scelta inesisitente.");
            break;
        }
    }
    while(opt!=1 || opt!=2);

    stampaarray(array, n);

    return 0;
}