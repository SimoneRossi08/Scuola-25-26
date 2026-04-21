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
    while (fread(&c, sizeof(Contatto), 1, fp)==1){
        printf("Nome: %s, Telefono: %s Sesso: %c\n", c.nome, c.telefono, c.sesso);
    }
    fclose(fp);
    printf("---------------\n");
}

void eliminaContatto(){

    char cercaNome[30], caercaTelefono[15];
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
    scanf(" %[^\n]", cercaNome);
    getchar();
    printf("Inserire il numero di telefono:");
    scanf(" %[^\n]", caercaTelefono);
    getchar();

    while(fread(&c, sizeof(Contatto), 1, fp)){
        if(strcmp(c.nome,cercaNome)==0 && strcmp(c.telefono,cercaTelefono)==0){
            printf("\nPersona trovata. ");
            printf("\nL'elemento sarà eliminato...");
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

void separaContatti(){

    Contatto c;
    FILE *fp=fopen("21042026.dat", "rb");
    FILE *fpF=fopen("21042026f.dat", "ab");
    FILE *fpM=fopen("21042026m.dat", "ab");
    if(fp==NULL){
        printf("Errore apertura file!\n");
        return;
    }
    if(fpF==NULL){
        printf("Errore apertura file!\n");
        return;
    }
    if(fpM==NULL){
        printf("Errore apertura file!\n");
        return;
    }

    while(fread(&c, sizeof(Contatto), 1, fp)){
        if(c.sesso=='f'||c.sesso=='F'){
            fwrite(&c,sizeof(Contatto),1,fpF);
        }
        else if(c.sesso=='m'||c.sesso=='M'){
            fwrite(&c,sizeof(Contatto),1,fpF);
        }
    }
    fclose(fp);
    fclose(fpF);
    fclose(fpM);

    fpF=fopen("21042026f.dat", "rb");
    fpM=fopen("21042026m.dat", "rb");

    printf("\n--- Rubrica Femmine ---\n");
    while (fread(&c, sizeof(Contatto), 1, fpF)==1){
        printf("Nome: %s, Telefono: %s Sesso: %c\n", c.nome, c.telefono, c.sesso);
    }
    printf("---------------\n");

    printf("\n--- Rubrica Maschi ---\n");
    while (fread(&c, sizeof(Contatto), 1, fpF)==1){
        printf("Nome: %s, Telefono: %s Sesso: %c\n", c.nome, c.telefono, c.sesso);
    }
    printf("---------------\n");

    fclose(fpF);
    fclose(fpM);
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
                separaContatti();
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