#include <stdio.h>

#define N 4

void riempiSpirale(int _mat[N][N]);
void stampaMatrice(int _mat[N][N]);

int main() {
    int mat[N][N];

    riempiSpirale(mat);
    stampaMatrice(mat);

    return 0;
}

void riempiSpirale(int _mat[N][N]) {
    int val = 1;
    int top = 0, bottom = N - 1;
    int left = 0, right = N - 1;

    while (val <= N * N) {
        //sinistra verso destra
        for (int i = left; i <= right; i++)
            _mat[top][i] = val++;
        top++;
         //alto verso il basso
        for (int i = top; i <= bottom; i++)
            _mat[i][right] = val++;
        right--;
        //destra verso sinistra
        for (int i = right; i >= left; i--)
            _mat[bottom][i] = val++;
        bottom--;
        //basso verso l' alto
        for (int i = bottom; i >= top; i--)
            _mat[i][left] = val++;
        left++;
    }
}

void stampaMatrice(int _mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", _mat[i][j]);
        printf("\n");
    }
}


    

    
