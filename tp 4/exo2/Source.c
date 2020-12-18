#define SEPARATEUR '/'
#define TAILLETAB1 20

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void affichage(int Tab[]) {
	int i = 0;

	for (i = 0; i < 20; i++) {
		printf("%d%c", Tab[i], SEPARATEUR);

	}

}

void affichage2(int Tab[]) {



	int j = 0;

	for (j = 19; j >= 0; j--) {

		int* Myptr = Tab[j];

		printf("%d%c", Myptr, SEPARATEUR);
	}

}



int main() {
	int Tab[TAILLETAB1];
	int  i = 0;


	for (i = 0; i < 20; i++) {

		Tab[i] = i + 1;
	}

	//affichage(Tab);
	affichage2(Tab);

}

