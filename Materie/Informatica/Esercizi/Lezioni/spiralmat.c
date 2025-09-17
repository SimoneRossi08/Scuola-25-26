/* Data una matrice quadrata di valori ordinarla a spirale. */

#include <stdio.h>
#define N 4

int main(){
    int m[N][N],v=1,ps=0, pi=N-1, s=0, d=N-1;

    while(v<=N*N){
        for(int i=s; i<=d; i++){
            m[ps][i]=v++;
        }
        ps++;

        for(int i=ps; i<=pi; i++){
            m[i][d]=v++;
        }
        d--;

        for(int i=d; i>=s; i--){
            m[pi][i]=v++;
        }
        pi--;

        for(int i=pi; i>=ps; i--){
            m[i][s]=v++;
        }
        s++;
    }

    for(int i=0; i<N;i++){
        for(int j = 0; j<N; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}