#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *torolBetu(char *elsoSzo, char *masodikSzo);

int main(){
	
	char beOlvas[101];
	
	while (gets(beOlvas) != NULL){
		
		char *token = strtok(beOlvas, " ");
		char *elsoSzo = (char *) malloc(strlen(token)+1 * sizeof(char));
		strcpy(elsoSzo, token);
		
		token = strtok(NULL, " ");
		char *masodikSzo = (char *) malloc(strlen(token)+1 * sizeof(char));
		strcpy(masodikSzo, token);

		puts(torolBetu(elsoSzo, masodikSzo));		
	}
	return 0;
}

char *torolBetu(char *elsoSzo, char *masodikSzo){
	int i , k = 0, elsoHossz = strlen(elsoSzo), masodikHossz = strlen(masodikSzo);
	int elsoSzoTomb[27] = {0}, masodikSzoTomb[27] = {0};
	char *vegsoTomb = (char *) malloc(elsoHossz * sizeof(char));
	
	for (i = 0; i < elsoHossz; i++)
		elsoSzoTomb[elsoSzo[i] - 97] = 1;
	
	for (i = 0; i < masodikHossz; i++)
		masodikSzoTomb[masodikSzo[i] - 97] = 1;

	for (i = 0; i < elsoHossz; i++)
		if (elsoSzoTomb[elsoSzo[i] - 97] != masodikSzoTomb[elsoSzo[i] - 97])
			vegsoTomb[k++] = elsoSzo[i];
		
	vegsoTomb[k] = '\0';
	
	return vegsoTomb;
}
