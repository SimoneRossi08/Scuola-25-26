/* Creare una rubrica telefonica utilizzando un file binario */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char telefono[20];
}contatto;

void aggContatto(){

    FILE *fp=fopen("26042026.bin", "wb");
    if(fp==NULL){
        printf("ERRORE");
        exit(1);
    }
    contatto c;

    printf("\nNome:");
    scanf("%[^\n]", c.nome);
    getchar();
    printf("\nNumero:");
    scanf("%[^\n]", c.telefono);
    getchar();

    fwrite(&c, sizeof(contatto), 1, fp);
    fclose(fp);
}

void visuRubrica(){
    FILE *fp=fopen("26042026.bin", "rb");
    if(fp==NULL){
        printf("ERRORE");
        exit(1);
    }
    contatto c;

    while(fread(&c, sizeof(contatto), 1, fp)==1){
        printf("\n%c, %c.", c.nome, c.telefono);
    }
    fclose(fp);
}

int main(){

    int opt;

    do{
        printf("\nMenu Rubrica:\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza rubrica\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &opt);
        getchar();

        switch(opt){
        case 1:
            aggContatto();
            break;
        case 2:
            visuRubrica();
            break;
        case 0:
            break;
        default:
            break;
        }
    }while(opt!=0);

    return 0;
}
