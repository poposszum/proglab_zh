#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double atlagosSzoHossz(int szoHossz, int szoDarabSzam);
void outPut(char **tomb, int hossz, double atlHossz);

int main(){
	
	char beOlvas[51];
	int i = 0, min = 50, szoHossz = 0, szoDarabSzam = 0;
	
	char **stringTomb = (char **) malloc(1 * sizeof(char *));
		
	while (gets(beOlvas) != NULL){
		
	
		stringTomb[i] = (char *) malloc(strlen(beOlvas)+1 * sizeof(char));
		strcpy(stringTomb[i], beOlvas);
		stringTomb[i][strlen(beOlvas)] = '\0';
		szoHossz+= strlen(beOlvas);
		szoDarabSzam++;
		
		stringTomb = (char **) realloc(stringTomb, ++i);		
	}
	
	stringTomb[i] = '\0';
	
	printf("%lf\n", atlagosSzoHossz(szoHossz, szoDarabSzam));
	outPut(stringTomb, szoDarabSzam, atlagosSzoHossz(szoHossz, szoDarabSzam));
	

	free(stringTomb);
	return 0;
}

double atlagosSzoHossz(int szoHossz, int szoDarabSzam){
	return (double) szoHossz / szoDarabSzam;
	
}

void outPut(char **stringTomb, int hossz, double atlHossz){
	
		int i;
	
	for (i = hossz-1; i >= 0; i--)
		if (strlen(stringTomb[i]) > atlHossz)
			puts(stringTomb[i]);
}
