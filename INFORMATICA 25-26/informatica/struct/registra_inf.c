/*registrare le informazione di alcuni libri es: titolo,autore, anno di pubblicazione*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char titolo[20];
    char autore [20];
    int anno;

}libri;

void caricaLibri(libri l[], int n);
void stampaLibri(libri l[], int n);
void cercalibri(libri l[], int n);
void menu(libri l[], int n);
void rimuoviLibri(libri l[], int n);

int main(){
    libri* libri;
    int n=0;
    do{
        printf("inserisci i libri da inserire: ");
        scanf("%d",&n);
    }while(n==0||n>=10);
    menu(libri, n);

}
void caricaLibri(libri l[], int n){
    for (int i=0;i<n;i++) {
        printf("titolo squadra: ");
        scanf("%s",l[i].titolo);
        printf("autore squadra ");
        scanf("%s",l[i].autore);
        printf("anno di stampa: ");
        scanf("%d",&l[i].anno);
       
        printf("\n");
    }
}
void stampaLibri(libri l[], int n){
    for(int i=0; i<n; i++){
        printf("titolo: %s", l[i].titolo);
        printf("autore: %s", l[i].autore);
        printf("anno: %d", l[i].anno);
    }
}
void cercalibri(libri l[], int n){
    for(int i=0; i<n; i++){

    }
}
void menu(libri l[], int n){
    int scelta;
    printf("=====Menù=====");
    do{
       printf("\n1.inserisci un libro: ");
       printf("\n2.cerca un libro: ");
       printf("\n3.rimuovi libri dalla lista: ");
       printf("\n4.esci: "); 

       switch(scelta){
        case 1:
            caricaLibri(l, n);
        break;
        case 2:
            cercaLibri(l, n);
        break;
        case 3:
            rimuoviLibri(l, n);
       }
       
    }while(scelta!=0&&scelta>5);
    

}