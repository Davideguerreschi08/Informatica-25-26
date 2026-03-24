/*verificare se una frase è palindroma
es: anna è palindroma
ciao non è palindroma */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Stringa;

 int lunghezza(Stringa s);
 int Palindroma(Stringa s, int dim);
    
int main(){

    int dim=0, palindroma=0; 

    Stringa s=(Stringa)malloc(50*sizeof(char));
    if(s==NULL){
        printf("Errore allocazione memoria\n");
        return 1;
    }
    printf("inserisci una stringa: ");
    fgets(s, 50, stdin);
    printf("\n%s",s);
    dim=lunghezza(s);
    printf("\n%d",dim);
    palindroma=Palindroma(s,dim);
    if(palindroma==1){
        printf("\nla stringa non è palindroma\n");
    }
    else{
        printf("\nla stringa è palindroma\n");
    }
}
    int lunghezza(Stringa s){
       int i=0;
       while(s[i]!='\0'){
        i++;
        }
        return i-1;
    }

     int Palindroma(Stringa s, int dim){
        int flag=0;
        int i;
        int j;
        for(i=0, j=dim-1; i<dim/2; i++,j--){
            if(s[i]!=s[j]){
                flag=1;
            }
            return flag;
        }

     }
