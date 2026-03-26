/* Esempio di apertura file in append*/

#include <stdio.h>

int main(){

    FILE *fp;
    char frase[200];
    char scelta;

    //apriamo il file in append
    fp=fopen("26032026.txt", "a");
    if(fp==NULL){
        printf("Errore...\n");
        return 1;
    }
    
    do{
        printf("Inserisci una frase: ");
        fgets(frase, sizeof(frase),stdin);
        fputs(frase,fp);

        printf("Vuoi inserire un'altra frase? (S/N)");
        scanf("%c", &scelta);
        getchar();

    }
    while(scelta=='s'||scelta=='S');

    fclose(fp);
    return 0;
}