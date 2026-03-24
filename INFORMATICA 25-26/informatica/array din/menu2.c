/*creare un array dinamico chiedendo all' utente la sua dimensione
il programma deve prendere le seguenti funzioni:
1. crea array
2. inserisci gli elementi all' interno dell' array
3. stampa dei valori
4. esci*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* creaArray(int _n); //chiedere di inserire la quantità di elementi
int* inserisciValori(int *v, int _n);//inserire i valori nell' array
void stampaValori(int *v, int _n);//stampare i valori

int main(){
    int *v=NULL;//putatore al vettore
    int n=0;
    
    do{
         printf("Inserisci la dimensione dell' array: ");
        scanf("%d", &n);
    }while(n<0);
    v=creaArray(n);
    v=inserisciValori(v,n);
    stampaValori(v,n);
    free(v);
       
    return 0;
}

    int* creaArray(int _n){

        int* _v=(int*)malloc(_n*sizeof(int));
        if (_v==NULL){
            printf("Errore di allocazione");
            return 1;
        }
        
}
int* inserisciValori(int *_v, int _n){
    for(int i=0;i<_n;i++){
        printf("Inserisci il valore: ");
        scanf("%d", &_v[i]);
    }
    return _v;
}
void stampaValori(int *_v, int _n){ 
    printf("hai inserito i seguenti elementi:\n");
    for(int i=0;i<_n;i++){
        printf("Valore %d\t", _v[i]);
    }
}