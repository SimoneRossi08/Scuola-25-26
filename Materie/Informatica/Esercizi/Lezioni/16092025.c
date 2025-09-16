/* Data una matrice di valori scambiare gli elementi della
    diagonale principale con la diagonale secondaria. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

void caricam(int (*_m)[N]){
	
	printf("Caricamento matrice...");
	
	for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            _m[i][j]=rand()%30+1;
        }
    }
    
    return 0;
}

void stampam(int *(_m)[N]){
	
	for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
}

void scambio(int (*_m)[N]){
	
	int t;
	
	for(int i=0; i<5; i++){
        t=m[i][i];
        m[i][i]=m[i][N-i-1];
        m[i][N-i-1]=t;
    }
}

int main(){
    
    int m[N][N]={0};
    srand(time(NULL));
    
    //caricamento matrice
    caricam(m);
    //stampa matrice
    stampam(m);
    //scambio diagonale
    scambio(m);
    //stampa matrice
    stampam(m);

   return 0;
}
