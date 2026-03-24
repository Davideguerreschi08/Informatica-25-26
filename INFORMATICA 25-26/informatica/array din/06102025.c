/*scrivi un programma in c che gestisca un iniseme di numeri interi usano un array dinamico
il programma deve permettere, tramite menù:
1.aggiungere il numero espaqndendo l'array con realloc
2.visuallizare tutti i numeri
3. cercare un numero specifico
4.ordinare i numeri in ordine crescente 
5 elimniare il numero scelto
6. uscire
*/
#include <stdio.h>
#include <stdlib.h>
int* allocazione(int *v, int dim);
void stampa(int *v, int dim);
void inserisci(int *v,int dim);
void bubblesort(int *v, int dim);
void scambio(int *x, int *y);
int ricerca(int *v, int dim);
int* elimina(int *v, int dim);
void menu();
int main(){
    int *v=NULL;
    int dim=0;
    int scelta;

    do{
        menu();
        scanf("%d",&scelta);
        switch(scelta){
            case 1:
                v=allocazione(v, dim+1);
                dim++;
                inserisci(v, dim);
                break;
            case 2:
                stampa(v, dim);
                break;
            case 3:
                if(ricerca(v, dim)!=-1){
                    printf("numero trovato in posizione %d\n", ricerca(v, dim));
                }else{
                    printf("numero non trovato\n");
                }
                break;
            case 4:
                bubblesort(v, dim);
                printf("numeri ordinati\n");
                break;
            case 5:
                v=elimina(v, dim);
                dim--;
                break;
            case 6:
                printf("uscita...\n");
                free(v);
                break;
            default:
                printf("scelta non valida\n");
        }
    }while(scelta!=6);
}
int* allocazione(int *v, int dim){
    int num;
    printf("numeri da inserire: ");
    scanf("%d",&num);
    v=(int*)realloc(v, dim*sizeof(int));
    if(v==NULL){
        printf("errore");
        exit(1);
    }
}
void stampa(int *v, int dim){
    for(int i=0; i<dim; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}
void scambio(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void bubblesort(int *v, int dim){
    for(int i=0; i<dim-1; i++){
        for(int j=0; j<dim-i-1; j++){
            if(v[j]>v[j+1]){
                scambio(&v[j], &v[j+1]);
            }
        }
    }
}
int ricerca(int *v, int dim){
    int num;
    printf("numero da cercare: ");
    scanf("%d",&num);
    for(int i=0; i<dim; i++){
        if(v[i]==num){
            return i;
        }
    }
    return -1;
}
int* elimina(int *v, int dim){
    int num=0; 
    int trovato=0;
    printf("numero da eliminare: ");
    scanf("%d",&num);
    for(int i=0;i<dim;i++){
        if(v[i]==num){
            trovato=1;
            trovato=i;
        }

    }
        if(trovato!=-1){
            for(int i=trovato;i<dim-1;i++){
            v[i]=v[i+1];
             dim--;
             v=(int*)realloc(v, dim*sizeof(int));
                printf("numero eliminato\n");
                if(v==NULL){
                printf("errore");
                exit(1);
            }
        }
        
    }
}
void menu(){
    printf("1. aggiungere il numero espaqndendo l'array con realloc\n");
    printf("2. visuallizare tutti i numeri\n");
    printf("3. cercare un numero specifico\n");
    printf("4. ordinare i numeri in ordine crescente\n");
    printf("5. elimniare il numero scelto\n");
    printf("6. uscire\n");
    printf("scelta: ");
}