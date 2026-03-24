#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

 void caricaMat(int (*_mat)[]);
 void stampa_mat(int (*_mat)[]);
 void scambiaDiagonale(int (*_mat)[N]);
int main(){
    int matrice[N][N]={0};
    srand(time(NULL));
    caricaMat(matrice);
    stampa_mat(matrice);
    scambiaDiagonale(matrice);
    stampa_mat(matrice);
}
void caricaMat(int (*_mat)[N]){
    printf("carichiamo la matrice: ");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            _mat[i][j]=rand()%31;
        }
    }
}
void stampa_mat(int (*_mat)[N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
                printf("%d\t", _mat[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}
void scambiaDiagonale(int (*_mat)[N]){
    for(int i=0;i<N;i++){
        int temp=_mat[i][i];
        _mat[i][i]=_mat[i][N-i];
        _mat[i][N-i]=temp;
    }
}