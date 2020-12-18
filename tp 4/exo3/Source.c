#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <math.h>


int main() {

	char nom[20];
	char prenom[20];
	char A;
	char sexe;

	printf("rentre ton prenom  :");
	scanf_s("%s", nom, _countof(nom));

	printf("rentre ton nom  :");
	scanf_s("%s", prenom, _countof(prenom));

	printf("rentre ton sexe H ou F  :");
	sexe = (char)_getch();
	if (sexe == 'H') {
		printf("cest un homme");
	}
	else {
		printf("cest une femme");
	}

	printf(" %s,%s", nom, prenom);




}