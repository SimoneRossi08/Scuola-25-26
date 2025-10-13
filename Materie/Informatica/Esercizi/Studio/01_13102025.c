/* 
Scrivere un programma in C che gestisca un insieme di numeri interi usando un array dinamico.
Il programma deve permettere, tramite menù:
    1. Aggiungere un numero (espandendo l’array con realloc)
    2. Visualizzare tutti i numeri
    3. Cercare un numero specifico
    4. Ordinare i numeri in ordine crescente
    5. Eliminare un numero scelto
    6. Uscire
*/

#include <stdio.h>
#include <stdlib.h>

int addnum(int *array, int *dim);

int main(){

    int *array=NULL;
    int opt,dim=0;

    printf("-----MENU------\n");
    printf("1. Aggiungi numero\n");
    printf("2. Visualizza numeri\n");
    printf("3. Cerca numero\n");
    printf("4. Ordina numeri (crescente)\n");
    printf("5. Elimina numero\n");
    printf("6. Esci\n");
    printf("Scelta: ");
    scanf("%d", &opt);

    do{
        switch(opt){
        case 1:
                addnum(&array, &dim);
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        default:
            printf("\nErrore! Opzione inesistente.");
            break;
        }
    }while(opt!=6);
}

int addnum(int *array, int *dim){

    int n=0;

    printf("\nInserisci un numero: ");
    scanf("%d", &n);

    array=(int*)realloc(n,(*dim+1)*sizeof(int));
    if(array==NULL){
        printf("Errore di allocazione!\n");
        return 1;
    }
    for(int i; i<*dim; i++){
        printf("%d", array[i]);
    }

    return array;
}