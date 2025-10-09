#include "stdstr.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * 
 */

string crstringdim(int n){

    string c=(string)malloc(n*sizeof(char));
    if(c==NULL){
        printf("Errore");
        exit(1);
    }
    fgets(c, n, stdin);

    return c;
}

/**
 * 
 */

 int clclunstring(string c){

    int dim=0;

    while(c[dim]!='\0'){
        dim++;
    }

    return dim;
}