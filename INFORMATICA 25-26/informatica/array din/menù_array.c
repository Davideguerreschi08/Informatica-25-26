/*Scrivere un programma in C che gestisca un insieme di numeri interi usando un array dinamico.
Il programma deve permettere, tramite menù:
    1. Aggiungere un numero (espandendo l’array con realloc) 
    2. Visualizzare tutti i numeri
    3. Cercare un numero specifico
    4. Ordinare i numeri in ordine crescente
    5. Eliminare un numero scelto
    6. Uscire*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10

void stampaArray(int v[], int dim);
void aggiungiNum(int **v, int *dim);
void cercaNum(int v[], int dim, int num);
void scambio(int *x, int *y);
void bubbleSort(int v[], int dim);
void eliminaNum(int v[], int *dim, int num);
void menu();
int main(){
    int *v[DIM];
    int scelta;
    int num;
    int dim=DIM;

    menu();
    printf("azione da compiere: \n");
    scanf("%d", &scelta);
    do{
        switch(scelta){
            case 1:
                aggiungiNum(&v, &dim);
            break;
            case 2:
                stampaArray(v, dim);
            break;
            case 3:
                printf("numero da cercare:\n");
                scanf("%d", &num);
                cercaNum(v, dim, num);
            break;
            case 4:
                bubbleSort(v, dim);
            break;
            case 5:
                printf("numero da eliminare:\n");
                scanf("%d", &num);
                eliminaNum(&v, &dim, num);
            break;
        case 6:
                printf("uscita in corso...\n");
            break;
        default:
                printf("scelta non valida\n");
            break;
     }
    }while(scelta!=6);

}

    void menu(){
        printf("1. Aggiungere un numero\n");
        printf("2. Visualizzare tutti i numeri\n");
        printf("3. Cercare un numero specifico\n");
        printf("4. Ordinare i numeri in ordine crescente\n");
        printf("5. Eliminare un numero scelto\n");
         printf("6. Uscire\n");
    }

    
    void stampaArray(int v[], int dim){
        for(int i=0; i<dim; i++){
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    void aggiungiNum(int **v, int *dim){
        int num;
        printf("numero da aggiungere: \n");
        scanf("%d", &num);
        *dim++;
        *v=(int*)realloc(*v, (*dim)*sizeof(int));
        (*v)[*dim-1]=num;
        if(*v==NULL){
            printf("errore di riallocazione\n");
            return 1;
        }
    }
    void cercaNum(int v[], int dim, int num){
        int trovato=0;
        for(int i=0; i<dim; i++){
            if(v[i]==num){
                trovato=1;
                printf("numero trovato in posizione %d\n", i);
            }
        }
        if(trovato==0){
            printf("numero non trovato\n");
        }
    }
    void scambio(int *x, int *y){
        int temp;
        temp=*x;
        *x=*y;
        *y=temp;
    }
    void bubbleSort(int v[], int dim){
        for(int i=0; i<dim-1; i++){
            for(int j=1; j<dim; j++){
                if(v[j-1]>v[j]){
                    scambio(&v[i], &v[j]);
                }
            }
        }
    }
        void eliminaNum(int v[], int *dim, int num){
            int trovato=0;
            for(int i=0; i<dim; i++){
                if(v[i]==num){
                    trovato=1;
                    for(int j=i; j<dim-1; j++){//sposto tutti gli elementi a sinistra
                        v[j]=v[j+1];
                    }
                    dim--;
                   *v=(int*)realloc(*v, (*dim)*sizeof(int));
                    (*v)[*dim-1]=num;
                }
            }
            if(trovato==0){
                printf("numero non trovato\n");
            }
        }