#include <stdlib.h>
#include <stdio.h>
#include <math.h>







int main() {

	float tableau[100];
	int i = 0;
	int j = 0;



	srand(time(NULL)); // intitialisattion a 0
	for (i = 0; i < 100; i++) {

		int nombre = 0;


		nombre = rand() % ((20));  //rand()%(borne_maximale - borne_minimale) + borne_minimale;

		nombre = nombre + 1;

		tableau[i] = nombre;

		printf("%f", tableau[i]);
		
		}

	




}
