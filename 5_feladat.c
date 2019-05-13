#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	
	int matrix[3][3], i, j;
	srand(time(NULL));
	
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			matrix[i][j] = rand() % 10 + 0;
			
			//matrix[0][1] = 0;
			//matrix[0][2] = 0;
			//matrix[1][2] = 0;
			
			for (i = 0; i < 3; i++){
				for (j = 0; j < 3; j++)
					printf("%d ",matrix[i][j]);
				printf("\n");
			}
			
		
			
				if (matrix[0][1] == 0 && matrix[0][2] == 0 && matrix[1][2] == 0)
				printf("YES");
					else printf("NO");
			
	return 0;
	
}
