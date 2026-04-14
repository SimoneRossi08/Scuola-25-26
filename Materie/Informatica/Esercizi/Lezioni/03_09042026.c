/* Creare una Rubrica che gestisca la memorizzazione
        dei contatti e ne visualizzi l'elenco */
    
#include <stdio.h>

typedef struct Contatto{

    char nome[30];
    char telefono[15];
    
}Contatto;

void aggiungiContatto(){

    FILE *fp=fopen("03_09042026.bin", "ab");
    if(fp==NULL){
        printf("Errore apertura file.\n");
        return;
    }

    Contatto c;

    printf("Inserisci il nome: ");
    scanf("%s[^\n]", &c.nome);
    printf("Inserisci il numero di telefono: ");
    scanf("%s[^\n]", &c.telefono);

    fwrite(&c, sizeof(Contatto), 1, fp);

    fclose(fp);
}

void stampaContatti(){

    FILE *fp=fopen("03_09042026.bin", "rb");
    if(fp==NULL){
        printf("Errore apertura file.\n");
        return;
    }

    Contatto c;

    printf("\n----RUBRICA----\n");
    while(fread(&c, sizeof(Contatto), 1, fp)==1){
        printf("Nome: %s, Telefono: %s\n", c.nome, c.telefono);
    }

    fclose(fp);
}

int main(){
    
    int scelta;

    do{
        printf("\nMenù Rubrica: \n");
        printf("1. Aggiungi contatto.\n");
        printf("2. Visualizza contatti.\n");
        printf("0. Esci.\n");
        scanf("%d", &scelta);

        switch (scelta){
            case 1:
                aggiungiContatto();
                break;
            case 2:
                stampaContatti();
                break;
            case 0:
                printf("Esci dal programma...");
                break;
            default:
                printf("Opzione inesistente...");
                break;
        }
    }
    while(scelta!=0);
}