/*codice di cifratura*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* stringa;

 stringa cifratura(stringa str, int chiave){
    for(int i=0; i <strlen(str); i++){
        str[i]+=chiave;
            if(str[i]+chiave>122){
            str[i]-=26;
        }
        if(str[i]+chiave>90){
          str[i]-=26;
        }
    }
}
int main(){

 int key;
 stringa str;

 printf("inserisci una frase: ");
 fgets(str, 50, stdin);
 printf("inserisci chiave di cifratura: ");
    scanf("%d", &key);
 cifratura(str, key);
  printf("stringa cifrata: %s\n", str);
  return 0;
}




