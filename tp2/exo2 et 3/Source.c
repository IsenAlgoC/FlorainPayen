// exo 2 Ecrire un programmenommé Exo2,qui permet à l'utilisateur d'entrer les trois dimensions d'un bagage 
//et vérifie qu'il est éligibleà l'embarquement dans la cabine d'un avion puisque sa taille n'excèdepas 55 cm x 35 cm x 25 cm.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main() {
	float d1 = 0;
	float d2 = 0;
	float d3 = 0;
	float x = 0;
	int test = 1;
	while (test == 1) {
		printf("Voulez vous tester un bagage, si oui taper 1, sinon taper 0\n"); // Savoir si l'utilasateur veut tester un bagage
		scanf_s("%d", &test);


		printf("rentre longueur L compris entre 1 et 150=");
		scanf_s("%f", &d1);

		printf("rentre largeur l compris entre 1 et 150 =");
		scanf_s("%f", &d2);

		printf("rentre hauteur h compris entre 1 et 150=");
		scanf_s("%f", &d3);

		if (d2 < d3) {
			x = d2;
			d2 = d3;
			d3 = x;

		}
		if (d1 < d2) {


			x = d1;
			d1 = d2;
			d2 = x;

		}
		if (d2 < d3) {
			x = d2;
			d2 = d3;
			d3 = x;
		}
	}

	//printf("%f,%f,%f\n", d1, d2, d3);

	if ((d1 >= 55) || (d2 >= 35) || (d3 >= 25)) {

		printf("NON valide\n\n");
	}
	else {
		printf(" valide\n\n");
	}




	//3 Ecrire un programme Exo3qui détermine si la valeur entrée au clavier, 
	//un entier naturelinférieur à 10000, représente une année bissextile ou non.
	int A = 0;

	printf("rentre l'annee de naissance");
	scanf_s("%d", &A);
	if ((A % 400 == 0) && ((A % 4 == 0) || (A % 100 != 0))) {
		printf("annee bissextile");
	}
	else {
		printf("non bissextile");
	}





}