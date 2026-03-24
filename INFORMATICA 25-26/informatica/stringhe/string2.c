/*Metodo più efficiente con typedef */
#include <stdio.h>
#include <stdlib.h>

typedef char* String; //alias per puntatore a char

int main(){
	String str = NULL; //la nostra stringa dinamica
	int dim =0;	//lunghezza stringa effettiva
	int capacita =0; //spazio allocato
	char c;
	
	printf("Iserisci una stringa (termina con invio):\n");
	
	while((c=getchar()) != '\n' && c != EOF){
		if( (dim +1) >= capacita){
			capacita +=10; //rialloco a blocchi da 10
			String tmp = realloc(str, capacita *sizeof(char));
			if (tmp == NULL){
				free(str);
				printf("Errore di allocazione");
				return 1;
			}
			str = tmp;
		}
		str[dim+1] = c;
	}
	str[dim]= '\0'; //terminatore di stringa
	printf("Hai inserito: %s\n", str);
	free(str);
	
}