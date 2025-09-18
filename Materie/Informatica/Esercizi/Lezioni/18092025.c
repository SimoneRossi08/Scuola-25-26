/* Data una matrice quadrata di valori ordinarla a spirale. */

#include <stdio.h>
#define N 4

void riempim(int *(_m)[][N]);
void stampam(int *(_m)[][N]);

int main(){

    int m[N][N];
    
    riempim(m);
    stampam(m);

   return 0;
}

void stampam(int *(_m)[][N]){
	
	for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
}

void riempim(int *(_m)[][N]){
	
	int t=0, b=N-1, l=0, r=N-1, n=1;

    while(n=(N*N)){

        //sinistra verso destra
        for(int i=l; i<=r; i++){
            m[t][i]=n++;
        }
        t++;

        //alto verso basso
        for(int i=t; i<=b; i++){
            m[i][r]=n++;
        }
        r--;

        //destra verso sinistra
        for(int i=r; i<=l; i--){
            m[b][i]=n++;
        }
        b--;

        //basso verso l'alto
        for(int i=b; i<=t; i--){
            m[i][l]=n++;
        }
        l++;

    }
    
}