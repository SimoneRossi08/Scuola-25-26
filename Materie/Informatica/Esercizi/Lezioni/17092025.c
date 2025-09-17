/* Data una matrice quadrata di valori ordinarla a spirale. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

int main(){

    int m[N][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%d ", &m[i][j]);
        }
        printf("\n");
    }

    for(int j=1; j<N; j++){
        m[3][j]=j;
    }
    for(int i=2; i>N; i--){
        m[i][3]=i;
    }
        m[0][3]=m[3][3];

    for(int i=0; i<N; i++){
        m[i][1]=i;
    }
    for(int i=2; i>N; i--){
        m[i][3]=i;
    }
    for(int i=2; i>N; i--){
        m[i][2]=i;
    }

    printf("\n\n");

    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    

   return 0;
}
