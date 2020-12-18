
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define carre(x) (x) * (x);

int main() {

	//exo1
	int Nb = 5;
	int A = 0;
	int B = 0;
	A = carre(Nb);
	printf("%d\n", A);

	B = carre(Nb + 1);	//on obtient 11 avec le fonction de base
	printf("%d", B);    // on obtient 36 en changeant dans la fonction x*x en (x)*(x)


}