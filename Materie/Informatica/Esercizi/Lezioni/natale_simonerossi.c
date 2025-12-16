#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Canzone {
    int id;
    char titolo[50];
    char artista[50];
    int durata;
    struct Canzone* next;
} Canzone;
typedef struct Lista {
    Canzone* testa;
    int lunghezza;
} Lista;

int id_univoco=0;
/* ---- Funzioni lista di canzoni disponibili ---- */
void stampa_canzone(Canzone *c);
void set_canzone(Canzone *c);
Lista* crea_lista();
void stampa_lista(Lista *l);
void inserisci_canzone_lista(Lista *l);
void ricerca_canzone_artista(Lista *l, char* artista);
void libera_memoria(Lista* l);
/* ---- Funzioni playlist (lista circolare) ---- */
void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist);
void stampa_playlist(Lista* playlist);
void cancella_canzone_playlist(Lista *playlist);

int main() {
    Lista* lista_canzoni=crea_lista();
    Lista* playlist=crea_lista();

    int scelta;
    char artista[50];

    do{
        printf("\n===== SPOTIFY 0.0.0.1 =====\n");
        printf("1. Inserisci nuova canzone nella lista\n");
        printf("2. Stampa lista canzoni\n");
        printf("3. Cerca canzoni per artista\n");
        printf("4. Aggiungi canzone alla playlist\n");
        printf("5. Stampa playlist\n");
        printf("6. Cancella canzone dalla playlist\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch(scelta){
            case 1:
                inserisci_canzone_lista(lista_canzoni);
                break;
            case 2:
                stampa_lista(lista_canzoni);
                break;
            case 3:
                printf("Inserisci artista da cercare: ");
                fgets(artista, 50, stdin);
                ricerca_canzone_artista(lista_canzoni, artista);
                break;
            case 4:
                inserisci_canzone_playlist(lista_canzoni, playlist);
                break;
            case 5:
                stampa_playlist(playlist);
                break;
            case 6:
                cancella_canzone_playlist(playlist);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }

    }
    while(scelta != 0);
    libera_memoria(lista_canzoni);
    libera_memoria(playlist);
    return 0;
}

void stampa_canzone(Canzone *c){
    printf("%s di %s - %d secondi\n", c->titolo, c->artista, c->durata);
}

void set_canzone(Canzone *c){
    id_univoco++;
    c->id=id_univoco;
    printf("\nID: %d", c->id);
    printf("\nInserisci titolo canzone: ");
    fgets(c->titolo, 40, stdin);
    printf("Inserisci artista canzone: ");
    fgets(c->artista, 40, stdin);
    printf("Inserisci durata canzone: ");
    scanf("%d", &c->durata);
    getchar();
}

Lista* crea_lista(){
    Lista* lista =(Lista*)malloc(sizeof(Lista));
    lista->testa=NULL;
    lista->lunghezza=0;
    return lista;
}

void stampa_lista(Lista *l){

    Canzone* current=l->testa;
    printf("Lista: ");
    while(current!=NULL){
        printf("%d->", current->dato);
        current=current->next;
    }
    printf("FINE LISTA\n");
    printf("Lunghezza: %d\n", l->lunghezza);
}
}

void inserisci_canzone_lista(Lista *l) {
    Canzone* nuovaCanzone=(Canzone*)malloc(sizeof(Canzone));
    set_Canzone(nuovaCanzone);
    nuovaCanzone->next=NULL;
    
    if(l->testa==NULL) {
        l->testa=nuovaCanzone;
    } else {
        Canzone* current=l->testa;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=nuovaCanzone;
    }
    l->lunghezza++;
}

void ricerca_canzone_artista(Lista *l, char* artista) {

}

void libera_memoria(Lista* l){

    Canzone* current=l->testa;
    while (current!=NULL) {
        Canzone*temp=current;
        current=current->next;
        free(temp);
    }
    free(l);
}

void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist){

    Lista* nuovaCanzone=(Lista*)malloc(sizeof(Lista));
    nuovaCanzone->dato=valore;
    
    if(lista_canzoni->testa==NULL){
        lista_canzoni->testa=nuovaCanzone;
        nuovaCanzone->next=nuovaCanzone;
    }
    else{
        Lista* current=lista_canzoni->testa;
        while(current->next!=lista->testa){
            current=current->next;
        }
        nuovaCanzone->next=lista_canzoni->testa;
        current->next=nuovaCanzone;
    }
    lista_canzoni->lunghezza++;
}
}

void stampa_playlist(Lista* playlist){

    if(lista->testa == NULL){
        printf("Lista vuota\n");
        return;
    }
    
    Lista* current=lista->testa;
    printf("Lista circolare: ");
    
    for (int i = 0; i < lista->lunghezza; i++){
        printf("%d -> ", current->dato);
        current = current->next;
    }
    printf("(ritorno a %d)\n", lista->testa->dato);
}

void cancella_canzone_playlist(Lista *playlist){

    if(playlist->testa==NULL){
        return;
    }
    if(playlist->testa->dato==valore){
        playlist* temp=playlist->testa;
        playlist->testa=playlist->testa->next;
        free(temp);
        playlist->lunghezza--;
        return;
    }
    Lista* current=playlist->testa;
    while (current->next!=NULL){
        if(current->next->dato==valore){
            Lista* temp=current->next;
            current->next=current->next->next;
            free(temp);
            playlist->lunghezza--;
            return;
        }
        current=current->next;
    }
}
