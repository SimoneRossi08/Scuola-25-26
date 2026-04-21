/* Creare una rubrica telefonica utilizzando un file binario */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char nome[30];
    char telefono[15];
    char sesso;

}Contatto;

void aggiungiContatto(){

    FILE *fp=fopen("21042026.dat", "ab"); // append in binario
    if(fp==NULL){
        printf("Errore apertura file!\n");
        return;
    }

    Contatto c;
    printf("Inserisci nome: ");
    scanf(" %[^\n]", c.nome);
    getchar();
    printf("Inserisci telefono: ");
    scanf(" %[^\n]", c.telefono);
    printf("Inserisci sesso: ");
    scanf(" %c", &c.sesso);
    getchar();

    fwrite(&c, sizeof(Contatto), 1, fp);
    fclose(fp);

    printf("Contatto aggiunto!\n");
}

void visualizzaRubrica(){

    FILE *fp=fopen("21042026.dat", "rb"); // lettura binaria
    if(fp==NULL){
        printf("Rubrica vuota!\n");
        return;
    }

    Contatto c;
    printf("\n--- Rubrica ---\n");
    while (fread(&c, sizeof(Contatto), 1, fp) == 1){
        printf("Nome: %s, Telefono: %s Sesso: %s\n", c.nome, c.telefono, c.sesso);
    }
    fclose(fp);
    printf("---------------\n");
}

void eliminaContatto(){

    char cerca[30];
    Contatto c;
    FILE *fp=fopen("21042026.dat", "rb");
    FILE *fpTmp=fopen("21042026_temp.dat", "wb");
    if(fp==NULL){
        printf("Errore apertura file!\n");
        return;
    }
    if(fpTmp==NULL){
        printf("Errore apertura file!\n");
        return;
    }

    printf("Inserire il nome:");
    scanf(" %[^\n]", cerca);
    getchar();

    while(fread(&c, sizeof(Contatto), 1, fp)){
        if(strcmp(c.nome,cerca)==0){
            printf("Nome trovato.");
            printf("L'elemento sarà eliminaato...");
        }
        else{
            fwrite(&c,sizeof(Contatto),1,fpTmp);
        }
    }

    fclose(fp);
    fclose(fpTmp);

    fp=fopen("21042026_temp.dat", "rb");
    fpTmp=fopen("21042026.dat", "wb");

    while(fread(&c, sizeof(Contatto), 1, fp)){
        fwrite(&c,sizeof(Contatto),1,fpTmp);
    }

    fclose(fp);
    fclose(fpTmp);
}

int main(){
    
    int scelta;

    do{
        printf("\nMenu Rubrica:\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza rubrica\n");
        printf("3. Elimina contatto\n");
        printf("4. Separa i contatti per sesso\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch(scelta){
            case 1:
                aggiungiContatto();
                break;
            case 2:
                visualizzaRubrica();
                break;
            case 3:
                eliminaContatto();
                break;
            case 4:

                break;
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida!\n");
        }
    }while(scelta != 0);

    return 0;
}