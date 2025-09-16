/**
 * funzione che stampa gli elementi di un vettore.
 * @param int [] vettore di interi 
 * @param int dimensione del vettore 
 * @param char separatore tra un elemento e un altro 
 */
void stampavettore(int v[], int d, char s);
/**
 * funzione che riempie un vettore con valori scelti dall'utente.
 * @param int [] vettore di interi 
 * @param int dimensione del vettore 
 */
void riempivettore(int v[], int d);
/**
 * funzione che riempie un vettore con numeri casuali compresi tra un minimo e un massimo.
 * @param int [] vettore di interi 
 * @param int dimensione del vettore 
 * @param int minimo valore minimo dei numeri casuali
 * @param int massimo valore dei numeri casuali
 */
void riempivettorecasuale(int v[], int d, int min, int max);
/**
 * funzione che calcola la media dei valori del vettore.
 * @param int [] vettore di interi 
 * @param int dimensione del vettore 
 */
void media(int v[],int dim);
/**
 * funzione che riempie un vettore con numeri casuali compresi tra un minimo e un massimo in ordine.
 * @param int [] vettore di interi 
 * @param int dimensione del vettore 
 * @param int minimo valore minimo dei numeri casuali
 * @param int massimo valore dei numeri casuali
 */
void riempivettoreordinatocasuale(int v[], int d, int min, int max);
/**
 * questa funzione restituisce la posizione del primo elemento in un array ordinato in ordine crescente che ha valore uguale alla variabile valore, se non trova l'elemento restituisce -1
 * @param int[]vettore in ingresso
 * @param int dimensione del vettore
 * @param int indice dell'elemento da cui parte la ricerca
 * @param int indice dell'elemento a cui arriva la ricerca
 * @param int valore da ricercare
 */
int ricercabinaria(int v[], int d, int estInf, int estSup, int val);
/**
 * questa funzione restituisce la posizione del primo elemento nell'array che ha valore uguale alla variabile valore, se non trova l'elemento restituisce -1
 * @param int* vettore in ingresso
 * @param int dimensione del vettore
 * @param int valore da ricercare
 * @return int posizione del primo elemento uguale a valore o -1 se non trovato
 */
int ricercasequenziale(int *v, int d, int val);
/**
 * funzione che conta la quantità di volte che appare il valore scelto.
 * @param int [] vettore di interi 
 * @param int dimensione del vettore 
 * @param int valore da contare
 */
int contavalori(int v[], int d, int val);
/**
 * funzione che scambia i valori contenuti di due valori.
 * @param int [] primo vettore di interi 
 * @param int [] secondo vettore di interi 
 * @param int dimensione del vettore 
 */
void scambiovettori(int v1[], int v2[], int d);
/**
 * funzione che ordina un vettore
 * @param int [] vettore in ingresso
 * @param int dimensione del vettore
 */
void bubblesort(int v[], int d);
/**
 * funzione che scambia il valore minimo con il valore massimo e viceversa di un vettore
 * @param int [] vettore in ingresso
 * @param int dimensione del vettore
 */
void scambiominmax(int v[], int d);