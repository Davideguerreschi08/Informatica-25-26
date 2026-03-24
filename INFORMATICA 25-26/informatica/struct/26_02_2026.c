/*
DATA LA STRUCT PRODOTTO
NOME
CODICE
QUANTITA'
PREZZO

ESEGUIRE

1.INSERIRE PRODOTTO
2.STMPARE ELENCO PRODOTTI
3.CERCARE UN PRODOTTO  PER CODICE
4.CALCOLARE IL VALORE DEL MAGAZZINO
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct prodotto{
    char nome[50];
    int codice;
    int quantita;
    float prezzo;
}prodotto;

void inserimento(prodotto* p, int n){
    for(int i=0; i<n; i++){
        printf("\nInserisci nome prodotto: ");
        scanf("%s", p[i].nome);
        printf("\nInserisci codice prodotto %d: ", i++);
        scanf("%d", &p[i].codice);
        printf("\nInserisci quantità prodotto %d: ", i++);
        scanf("%d", &p[i].quantita);
        printf("\nInserisci prezzo prodotto %d: ", i++);
        scanf("%f", &p[i].prezzo);
    }
}

void stampa(prodotto* p, int n){
    for(int i=0; i<n; i++){
        printf("\nNome prodotto %d: %s\n", i++, p[i].nome);
        printf("\nCodice prodotto %d: %d\n", i++, p[i].codice);
        printf("\nQuantità prodotto %d: %d\n", i++, p[i].quantita);
        printf("\nPrezzo prodotto %d: %.2f\n", i++, p[i].prezzo);
    }
}

void cercaCodice(prodotto* p, int n, int codice){
    for(int i=0; i<n; i++){
        if(p[i].codice==codice){
            printf("\ncodice prodotto: %d", p[i].codice);
            printf("\nnome prodotto %d: %s\n", i++, p[i].nome);
            printf("\nquantità del prodotto: %d", p[i].quantita);
            printf("\nprezzo del prodotto: %f", p[i].prezzo);
        }
    }
}

void valoreMagazzino(prodotto* p, int n){
    int somma=0;
    for(int i=0; i<n; i++){
        somma=p[i].prezzo;
        somma+=somma;
        printf("\nil valore del magazzino è: %f", somma);
    }
}
int main(){

    prodotto* p=(prodotto*)malloc(sizeof(prodotto));
    int scelta;
    int n;
    int code;

    printf("numero prodotti da inserire: ");
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        inserimento(p, n);
    }
    printf("\ncosa vuoi visuallizzare: ");
    printf("\n1)stampare l'elenco dei prodotti ");
    printf("\n2)cercare un prodott per codice  ");
    printf("\n3)mostrare il valore del magazzino");
    scanf("%d", &scelta);

    do{
        if(scelta==1){
            stampa(p, n);
        }else if(scelta==2){
            printf("inserisci il codice del prodotto: ");
            scanf("%d", &code);
            cercaCodice(p, n, code);
        }else if(scelta==3){
            valoreMagazzino(p, n);
        }
    }while(scelta!=3);

    return 0;
}