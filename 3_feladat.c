#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(char **stringTomb, int hossz);
void kiirSzo(char **stringTomb, int hossz);

int main(){
	
	char beOlvas[51];
	int i = 0, min = 50;
	
	char **stringTomb = (char **) malloc(1 * sizeof(char *));
		
	while (gets(beOlvas) != NULL){
	
		stringTomb[i] = (char *) malloc(strlen(beOlvas)+1 * sizeof(char));
		strcpy(stringTomb[i], beOlvas);
		stringTomb[i][strlen(beOlvas)] = '\0';
		
		stringTomb = (char **) realloc(stringTomb, ++i);		
	}
	
	stringTomb[i] = '\0';
	
	printf("minimum: %d\n", minimum(stringTomb, i));	
	kiirSzo(stringTomb, i);
	

	free(stringTomb);
	return 0;
}

int minimum(char **stringTomb, int hossz){
	int i, min = 50;
	
	for (i = 0; i < hossz; i++)
		if (strlen(stringTomb[i]) < min)
			min = strlen(stringTomb[i]);
	
	return min;
}

void kiirSzo(char **stringTomb, int hossz){
	int i, min = minimum(stringTomb, hossz);
	
	for (i = hossz-1; i >= 0; i--)
		if (strlen(stringTomb[i]) > min * 2)
			puts(stringTomb[i]);
}

