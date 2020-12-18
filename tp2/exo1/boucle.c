#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main() {


	int n = 100;
	int s = 0;
	int i = 0;

	//ex1 avec for 

	for (i = 1; i <= n; i++) {
		s = s + i;
	}

	printf(" somme %d\n", s);
	s = 0;
	i = 0;

	//ex1 while

	while (i <= n) {
		s = s + i;
		i++;
	}
	printf("somme %d\n", s);
	s = 0;
	i = 0;

	// while do

	do {
		s = s + i;
		i++;
	} while (i <= n);


	printf("somme %d\n", s);

	s = 0;
	i = 0;


	// SUITE EXO 1 Trouver la valeur maximum de n sans dépassement de capacité

	unsigned short int S = 0;
	int m = 3645;

	while (i <= m && (65535 - S >= i)) {

		S = S + i;
		i++;


	}
	printf("somme %d %d\n", S, i);
	S = 0;
	i = 0;
	m = 0;
	s = 0;


	// Demander la valeur de n à l’utilisateur

	printf("rentre valeur max=");
	scanf_s("%f", &m);

	for (i = 1; i <= m; i++) {
		s = s + i;
	}

	printf(" somme %d\n", s);
	s = 0;
	i = 0;










}