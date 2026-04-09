/* Lettura di un file binario */

#include <stdio.h>

int main(){

    int n[3];
    FILE *fp=fopen("01_09042026.bin", "rb");
    if(fp==NULL){
        printf("Errore apertura file.\n");
        return 1;
    }

    fread(n, sizeof(int), 3, fp);

    for(int i=0; i<3; i++){
        printf("%d\n", n[i]);
    }

    fclose(fp);
}