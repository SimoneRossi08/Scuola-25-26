/* Scrivi un programma in C che gestisca un insieme di
        numeri interi usano un array dinamico.
    Il programma deve permettere, tramite menù:
    1. Aggiungere un numero (espandendo l'array con realloc)
    2. Visualizzare tutti i numeri
    3. Cercare un numero specifico
    4. Ordinare i numeri in ordine crescente
    5. Eliminare un numero scelto
    6. Uscire                                               */

#include <stdio.h>
#include <stdlib.h>

void stampaarray(int *_array, int _n){

    for(int i=0; i<_n; i++){
        printf("%d ", _array[i]);
    }
    printf("\n");
}

int main(){

    int array=NULL;
    int opt;

    printf("Quale opzione vuole eseguire? \n");
    printf("1. Aggiungi numero\n");
    printf("2. Visualizza numeri\n");
    printf("3. Cerca numero\n");
    printf("4. Ordina numeri (crescente)\n");
    printf("5. Elimina un numero\n");
    printf("6. Esci\n");
    scanf("%d", &opt);

    do{
        switch(opt){
        case 1:
                printf("Inserisci un numero: ");
                scanf("%d", &n);
                n=(int*)realloc(n, (d+1)*sizeof(int));
                if(n==NULL){
                    printf("Errore di allocazione!\n");
                    return 1;
                }
                numeri[d]=n;
                d++;
                printf("Numero aggiunto!\n");
            break;      
        case 2:
                stampaarray(array,n)
            break;
        case 3:
            printf("Numero da cercare: ");
            scanf("%d", &n);
            ne=0;
            for(int i=0; i<d; i++){
                if(numeri[i]==n) {
                    printf("ne all'indice %d\n", i);
                    ne = 1;
                    break;
                }
            }
            if (!ne) printf("Numero non ne.\n"); 
            break;
        case 4:
            for(int i=0; i<d-1; i++){
            for(int j=0; j<d-i-1; j++){
                    if(numeri[j]>numeri[j+1]){
                        int tmp=numeri[j];
                        numeri[j]=numeri[j+1];
                        numeri[j+1]=tmp;
                    }
                }
            }
            printf("Numeri ordinati:\n");
            for(i=0; i<d; i++){
            	printf("%d ", numeri[i]);
			}
            printf("\n")
            break;
        case 5:
            printf("Numero da eliminare: ");
            scanf("%d", &n);
            ne=-1;
            for(i= 0; i <d; i++){
                if(numeri[i]==n){
                    ne=i;
                    break;
                }
            }
            if(ne!=-1){
                for (i=ne; i<d-1; i++){
                    numeri[i] = numeri[i+1];
                }
                d--;
                n=realloc(n, d*sizeof(int));
                printf("Numero eliminato.\n");
            }
            else{
                printf("Numero non ne.\n");
            }
            break;
        case 6:
                free(n);
                printf("Programma terminato.\n");
                return 0;
            break;
        default:
            printf("Errore! Scelta inesisitente.");
            break;
        }
    }
    while(opt!=1 || opt!=2 || opt!=3 || opt!=4 || opt!=5 || opt!=6);

    return 0;
}