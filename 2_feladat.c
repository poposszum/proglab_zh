#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[]){
	
	FILE *f = fopen(argv[1],"r");
	
	if(f == NULL){
		printf("A fajl nem letezik!\n");
		return -1;
	}
	
	char beOlvas[301];
	char legHosszabb[301];
	int max = -1;
	
		while (fgets(beOlvas, 300, f) != NULL){
			
			//puts(beOlvas);
			
			if (isupper(beOlvas[0])){
				puts(beOlvas);
				
				if (strlen(beOlvas) > max){
					max = strlen(beOlvas);
					strcpy(legHosszabb, beOlvas);
					legHosszabb[strlen(beOlvas)+1] = '\0';
				}
			}
		}
		
		puts(legHosszabb);
	
	fclose(f);
	
	return 0;
}
