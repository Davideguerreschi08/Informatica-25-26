/*Scrivi un programma in C che:
1. chiede all' utente quanti numeri interi vuole inserire;
2. alloca dinamicamente un array di quella dimensione con malloc()
3. permette all' utente di inserire dei numeri
4 chiede all'utente se vuole aumentare la dimensione dell' array
- se si richiede la nuova dimensione e usa realloc() per ridimensionarlo
- permette quindi di inserire i nuovi valori negli spazi aggiunti 
5. stapa tutti gli elementi dell' array*/
#include <stdio.h>
#include <stdlib.h>

int* allocazione(int _n);
void stampaArray(int v, int _n);
int* riempiArray(int v[], int _n);
void menu();

int main(){
    int scelta;
     int *_v = NULL;
    int n = 0;

    menu();
    printf("scelta: ");
    scanf("%d",&scelta);
    do{
    switch(scelta){
        case 1:
            printf("quanti numeri vuoi inserire? ");
            scanf("%d",&n);
            *_v=allocazione(n);
            
            break;
        case 2:
            allocazione(n);

            break;
        case 3:
            riempiArray(_v,n);
            stampaArray(_v,n);
            break;
            case 4:
                printf("vuoi aumentare la dimensione dell' array? (1=si/0=no) ");
            scanf("%d",&scelta);
            if(scelta==1){
                int _n;
                printf("nuova dimensione: ");
                scanf("%d",&_n);
                _v=(int*)realloc(_v,_n*sizeof(int));
                if(_v==NULL){   
                    printf("ERRORE DI REALLOCAZIONE!!");
                    exit(1);
                }
                riempiArray(_v+ n, _n - n);
                n=_n; 
                stampaArray(_v,n);
                
            }
            break;
            case 5:
                stampaArray(_v,n);
                break;
            case 6:
                free(_v);
                exit(0);
                break;
            
            default:
                printf("scelta errata!");
    }
    }while(scelta!=6);
    
}
int* allocazione(int _n){
    int *v=(int*)malloc(_n * sizeof(int));
    if(v==NULL){
        printf("ERRORE DI ALLOCAZIONE!!");
        exit(1);
    }
    return v;
}
int* riempiArray(int *v, int _n){
    int num;
    for(int i=0; i<_n; i++){
        printf("numero da inserire: ");
        scanf("%d",&num);
        v[i]=num;
    }
}void menu(){
    printf(" 1. chiede all' utente quanti numeri interi vuole inserire\n");
    printf("2. alloca dinamicamente un array di quella dimensione con malloc()\n");
    printf("3. permette all' utente di inserire dei numeri\n");
    printf("4 chiede all'utente se vuole aumentare la dimensione dell' array\n");
    printf("5. stapa tutti gli elementi dell' array\n");
    printf("6. esci\n");
}