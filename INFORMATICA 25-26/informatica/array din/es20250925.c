/* Esempio di malloc e realloc insieme
    Scrivere un programma in linguaggio C che:
    1. Allochi dinamicamente un array iniziale di n numeri interi con malloc;
    2. inserimento dei valori;
    3. stampi l'array;
    4. calcoli la somma dei valori multipli di 3;
    5. creiamo un nuovo array con solo i numeri d
*/
#include <stdio.h>
#include <stdlib.h>

int* allocazione(int n);
void riempiArray(int *v, int n);
void stampaArray(int *v, int n);
void sumMultipli(int *v, int n);
int* splitd(int *v, int n, int *_dim);
void menu();

int main(){
 int scelta;
    int *_v = NULL;
    int n = 0;
    int *dispari = NULL;
    int n_disp = 0;

    do {
        menu();
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("Quanti numeri vuoi inserire? ");
                scanf("%d", &n);
                if (_v != NULL) {
                    free(_v); // Evita memory leak
                }
                _v = allocazione(n);
                break;

            case 2:
                if (_v == NULL) {
                    printf("Devi prima allocare l'_v (opzione 1).\n");
                } else {
                    riempiArray(_v, n);
                }
                break;

            case 3:
                if (_v == NULL) {
                    printf("_v non ancora creato.\n");
                } else {
                    printf("Contenuto dell'_v:\n");
                    stampaArray(_v, n);
                }
                break;

            case 4:
                if (_v == NULL) {
                    printf("_v non ancora creato.\n");
                } else {
                    sumMultipli(_v, n);
                }
                break;

            case 5:
                if (_v == NULL) {
                    printf("_v non ancora creato.\n");
                } else {
                    if (dispari != NULL) {
                        free(dispari); // libera _v precedente se presente
                    }
                    dispari = splitd(_v, n, &n_disp);
                    printf("Nuovo _v con soli numeri dispari:\n");
                    stampaArray(dispari, n_disp);
                }
                break;

            default:
                printf("Scelta non valida. Riprova.\n");
        }

    } while (scelta != 0);

    // Libera la memoria se allocata
    free(_v);
    free(dispari);
}
int* allocazione(int n){
    int *v=(int*)malloc(n * sizeof(int));
    if(v==NULL){
        printf("ERRORE DI ALLOCAZIONE!!");
        exit(1);
    }
    return v;
}
void menu(){
    printf(" 1. Allochi dinamicamente un array iniziale di n numeri interi con malloc\n");
    printf("2. inserimento dei valori\n");
    printf("3. stampi l'array\n");
    printf("4. calcoli la somma dei valori multipli di 3\n");
    printf("5. creiamo un nuovo array con solo i numeri dispari\n");
}
void riempiArray(int *v[], int n){
    int num;
    for(int i=0; i<n; i++){
        printf("numero da inserire: ");
        scanf("%d",&num);
        *v[i]=num;
    }
}
void stampaArray(int *v[], int n){
    for(int i=0; i<n;i++){
        printf("%d",v[i]);
    }
}
void sumMultipli(int *v[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        if(*v[i]%3==0){
            sum+=*v[i];
        }
    }
    printf("la somma dei multipli di 3 è: %d", sum);
}
int* splitd(int *v, int n, int *_dim) {
    int *d=NULL;
    int cnt=0;

    for (int i = 0;i<n;i++) {
        if (v[i]%2!=0) {
            cnt++;
            d = realloc(d, cnt * sizeof(int));
            if (d == NULL) {
                printf("Errore di realloc\n");
                exit(1);
            }
            d[cnt - 1] = v[i];
        }
    }

    *_dim = cnt;
    return d;
}