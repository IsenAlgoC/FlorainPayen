#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

	//ex1
	float tableau[100] ;
	int i=0;
	float A=0;
	int c = 0;

	for (i = 0; i < 100; i++) {
		tableau[i] = 0;
	}
		while (A != -1) {

			printf("rentre un numero  :");
			scanf_s("%f", &A);
			tableau[i] = A;
			printf("%f", tableau[i]);
			i = i + 1;
			if (A >= 0) {
				c = c + 1;

			}



		}
	
	
	for (i = 0; i <100; i++) {
		

		printf("%.2f\n", tableau[i]);


	}


}