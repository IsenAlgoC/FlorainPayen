#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tp4.h"

int main() {

	HEURE heurededebut;
	HEURE heuredefin;
	HEURE duree;

	heurededebut.heure = 12; heurededebut.minute = 30;
	duree.heure = 0; duree.minute = 45;

	//typedef struct point { int X; int Y; } Point ; 
	// et on declare les variables de ce type dont on a besoin :
	// Point P1, P2;
	// l'accès aux différents champs de P1 ou de P2 se fait à l'aide d'un '.' :
	// P1.X = 10 ; P1.Y = 20; 
	//dans notre cas P1=heuredebut x=heure y=minute ET typedef struct heure{ int heure; int minute; } HEURE;

	heuredefin.heure = heurededebut.heure + duree.heure;
	heuredefin.minute = heurededebut.minute + duree.minute;
	if (heuredefin.minute > 60) {
		heuredefin.minute = heuredefin.minute % 60;
		heuredefin.heure = heuredefin.heure + 1;

	}

	printf("\n heuredefin = ( %d , %d) \n", heuredefin.heure, heuredefin.minute);


}
