/* stringhe con malloc */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *buffer; //puntatore alla stringa buffer
    int len;

    printf("Inserisci la lunghezza della stringa: ");
    scanf("%d", &len);

    //alloco lo spazio in memoria
    buffer=(char*)malloc((len+1)*sizeof(char));
    if(buffer==NULL){
        return 1;
    }

    printf("Inserisci una stringa: ");
    fgets(buffer, (len+1), stdin);
    //scanf("%s", buffer);
    printf("\nHai inserito: %s", buffer);

    free(buffer);
}