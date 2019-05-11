/*
2. feladat

Irjon programot, amely a standard bemenetrol soronkent ket legfeljebb 100 karakter hosszusagu sztringet olvas be allomanyvegjelig.
A ket szi kizarolag az angol ABC kisbetuit tartalmazza es pontosan egy darab szokoz karakterrel van elvalasztva. Irjon fuggvenyt,
mely parameterkent, megkap 2 sztringet es a ket string megvaltoztatasa nelkul letrehoz egy uj stringet, mely azokat a karaktereket tartalmazza, mely az elso
sztringben benne van, de a masodikban nincs. Hivja meg a fuggvenyt minden beolvasott szoparra es irja ki a standard kimenetre soronkent a letrohozott uj
sztringet.
alma abba
abcdef chd
aabddef af
lm
abef
bdee
*/


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
