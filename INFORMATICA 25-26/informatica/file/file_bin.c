#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp=fopen("numeri.bin", "wb");
    int numeri[3]={10,20,30};

    if(fp==NULL){
        printf("Errore apertura file\n");
        return 1;
    }
    fwrite(numeri, sizeof(int), 3, fp);

    fclose(fp);

}