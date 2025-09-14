#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampavettore(int v[], int d, char s){

    for(int i=0; i<d; i++){
        printf("%d%c", v[i], s);
    }
}

void riempivettore(int v[], int d){

    for(int i=0; i<d; i++){
        printf("Inserici l'elemento in posizione di %d: ", i);
        scanf("%d", &v[i]);
    }
}

void riempivettorecasuale(int v[], int d, int min, int max){

    srand(time(NULL));
    for(int i=0; i<d; i++){
        v[i]=rand()%(max-min+1)+min;
    }
}

void media(int v[],int dim){

    int somma=0;
    float media=0;

    for(int i=0; i<dim; i++){
        somma+=v[i];
    }

    media=somma/dim;
    printf("\nLa media corrisponde a %.2f. ", media);
}

void spostadx(int v[], int d, int p){

    for(int i=d; i>p; i--){
        v[i]=v[i-1];
    }
}
int trovaposizione (int v[], int d, int n){

    int i=0;
    
    while(v[i]<n && i<d){
        i++;
    }
    return i;
}

void riempivettoreordinatocasuale(int v[], int d, int min, int max){

    srand(time(NULL));
    int n, p;

    v[0]=rand()%(max-min+1)+min;

    for(int i=1; i<d; i++){
        n=rand()%(max-min+1)+min;
        p=trovaposizione(v, i, n); 
        spostadx(v, i, p);
        v[p]=n;
    }
}

int ricercabinaria(int v[], int d, int estInf, int estSup, int val){

    int media=(estSup+estInf)/2;
    if(estInf>estSup){
        return -1;
    }
    if(v[media]==val){
        return media;
    }
    if(v[media]>val){
        return ricercabinaria(v ,d, estInf, media-1, val);
    }
    else{
        return ricercabinaria(v ,d, media+1, estSup, val);
    }
}

int ricercasequenziale(int *v, int d, int val){

    for(int i=0; i<d; i++){
        if(v[i]==val){
            return i;
        }
    }
    return -1;
}

int contavalori(int v[], int d, int val){

    int cnt=0;

    for(int i=0; i<d; i++){
        if(v[i]==val){
            cnt++;
        }
    }
    return cnt;
}

void scambiovettori(int v1[], int v2[], int d){

    int t[d];

    for(int i=0; i<d; i++){
        t[i]=v1[i];
        v1[i]=v2[i];
        v2[i]=t[i];
    }
}

void bubblesort(int v[], int d){

    int t,flag=0,i=0;

    while(flag==0){
        flag=1;

        for(int j=0; j<d-1-i; j++){
            if(v[j]>v[j+1]){
                flag=0;

                t=v[j];
                v[j]=v[j+1];
                v[j+1]=t;
            }
        }
        i++;
    }
}

void scambiominmax(int v[], int d){

    int min,max,imax,imin;

    min=v[0];
    max=v[0];

    for(int i=1; i<d; i++){
        if(v[i]<min){
            min=v[i];
            imin=i;
        }
        if(v[i]>max){
            max=v[i];
            imax=i;
        }
    }

    v[imin]=max;
    v[imax]=min;
}