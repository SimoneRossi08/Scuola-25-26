/*	Si vuole gestire la raccolta dei punteggi di sportivi, 
	ottenuta tramite prove selettive, con valori che oscillano 
	dallo 0 ad un massimo di 180 punti. 
	Lo studente deve gestire le seguenti richieste tramite un menù: 
	1. l'aggiornamento periodico dei nuovi punteggi inseriti; 
	   l'elenco ne può contenere al massimo 1000;
	   (N.B. non è detto che l'elenco contenga effettivamente tutti e 1000);
	2. visualizzare a schermo i punteggi inseriti;
	3. determinare quanti hanno totalizzato un punteggio superiore ai 150 e 
	   quanti un punteggio inferiore a 80;
	4. successivamente all'inserimento di tutti i punteggi l'array viene modificato 
	   eliminando i punteggi inferiori a 50;
	5. ordinare i punteggi restanti dal più alto in classifica;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand(time(NULL));
	
	int* array; //dichiarazione dell'array
    int opt; //dichiarazione dell'opzione dell'utente
	int dim; //dichiarazione della dimensione
	
	array=rand()%179+1;

    do{
        printf("\nMenu:\n");
        printf("1. Aggiorna i punteggi.\n");
        printf("2. Visualizza i punteggi.\n");
        printf("3. Mostra i punteggi minori di 80 e maggiori di 150.\n");
        printf("4. Elimina i punteggi minori di 50.\n");
        printf("5. Ordina i punteggi.\n");
        printf("6. Esci.\n");
        printf("\nScelta: ");
        scanf("%d", &opt);

        switch(opt){
            case 1:
					array=aggpunt(array,dim); //Aggiornamento dei punteggi
                break;
            case 2:
					stampunt(array,dim); //Stampa i punteggi
                break;
            case 3:
					staminmax(array,dim); //Stampa i punteggi minori di 80 e maggiori di 150
                break;
            case 4:
					array=elimpunt(array,dim); //Elimina un punteggio
                break;
            case 5:
					array=ordipunt(array,dim); //Ordina il punteggio in ordine decrescente e stampa la classifica
                break;
            case 6:
            	break;
            default:
                printf("Scelta non valida. Riprova.\n");   
                break;
        }
    }
    while(opt!=6);
    printf("Uscita dal programma.\n");
    
    return 0;
}

int aggpunt(int* array, int dim){
	
	int n;
	
	do{
	    printf("\nInserisci il punteggio da aggiungere: ");
	    scanf("%d", &n);
	}
	while(n<=0||n>=180);
    
    array=(int*)realloc(array, (dim+1)*sizeof(int));
    if(array==NULL){
        printf("\nErrore! Allocazione fallita.\n");
        return NULL;
	}
    array[dim]=n;
    dim+1;
    printf("\nPunteggio aggiunto con successo.\n");
    
    return *array;
}

int stampunt(int* array, int dim){
	
	int i;

    printf("\nPunteggi: ");
        
    for(i=0; i<dim; i++){
        printf("%d\t", array[i]);
    }
}

int staminmax(int* array, int dim){
	
	int i, cnt=0;
	
    printf("\nPunteggi minori di 80 e maggiori di 150: ");
        
    for(i=0; i<dim; i++){
        if(array[i]<80 && array[i]>150){
        	cnt++;
    	}
    }
    printf("\n%d", cnt);
}

int elimpunt(int* array, int dim){
	
	int n,i,j;
	
	printf("Inserisci il punteggio da eliminare: ");
    scanf("%d", &n);
    
    for(i=0;i<dim; i++){
        if(array[i]==n){
            for(j=i; j<dim-1; j++){
	            array[j]=array[j+1];
	            dim-1;
            }
        }
    }
    
    return *array;
}

int ordipunt(int* array, int dim){
	
	int i,j,tmp;
	
	for(i=0; i<dim-1; i++){
        for(j=0; j<dim-i-1; j++){
            if(array[j]<array[j+1]){
                tmp=array[j];
                array[j]=array[j+1];
                array[j+1]=tmp;
            }
        }
    }
    
    printf("\nClassifica: ");
        
    for(i=0; i<dim; i++){
        printf("%d\n", array[i]);
    }
	
	return *array;
}
