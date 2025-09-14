/*Data una matrice di valori scambiare gli elementi della
    diagonale principale con la diagonale secondaria. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int t, m[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
 
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    printf("\n");

    for(int i=0; i<5; i++){
        t=m[i][i];
        m[i][i]=m[i][4-i];
        m[i][4-i]=t;
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}