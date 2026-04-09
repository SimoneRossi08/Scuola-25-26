/* Aprire/Creare un file binario */

#include <stdio.h>

int main(){

    int n[3]={10,20,30};
    FILE *fp=fopen("01_09042026.bin", "wb");
    if(fp==NULL){
        printf("Errore apertura file.\n");
        return 1;
    }
    
    fwrite(n, sizeof(int), 3, fp);
    
    fclose(fp);
}