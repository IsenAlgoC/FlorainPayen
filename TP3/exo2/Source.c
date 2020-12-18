#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

	unsigned int Nb = 2868838400;
	int A;
	int B;
	A = sizeof(Nb);
	printf("le nombre d octets utilises pour representer le nombre entier est %u\n", A);  //sizeof taille de mon nombre en octet
	B = A * 8;
	printf("le nombre de  bits utilises pour representer le nombre entier est %d\n", B);  // 1 octets c 8 bits

	int i;
	for (i = 0; i < B; i++) {

		printf(" bit %d: ", i);
		if ((1 & Nb) == 1) {
			printf("ON\n");
		}
		else {
			printf("OFF\n");
		}
		Nb = Nb >> 1;  //je decale mon nombre a droite de 1 pour enleve ma derniere valeur

	}
	printf("\nbye");
}