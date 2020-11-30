#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include"tab.h"
#define TAILLEAJOUT 50
#define TAB2SIZE 100

int initTab(int* tab, int size) {           //création premiere fonction qui remplitun tableau d’entiers de taille size avec des zéros

	int i;
	if ((tab == NULL) || (size < 0)) {     //premiere condition pour une valeur de retour -1

		return -1;
	}

	else {                                 //sinon valeur de retour size
		for (i = 0; i < size; i++) {

			*(tab + i) = 0;                // on affecte 0 à la variable pointée par chaque adresse du tableau
		}
		return size;
	}
}

int afficheTab(int* tab, int size, int nbElts) {     //meme principe mais avec le nombre d'elements en plus
	int i;
	if ((tab == NULL) || (size < 0) || (size < nbElts)) {

		return -1;
	}
	else {
		for (i = 0; i < nbElts; i++) {             // une boucle qui s'arrete cette fois au nombre d'elements choisis
			printf("%d ", *(tab + i));             //affichage de notre tableau
		}
		return 0;
	}



}



int unavingtTab(int* tab, int size, int nbElts) {  //creation fonction pour remplir les nbElts (20 dans notre exercice) 
	for (int i = 0; i < nbElts; i++) {             //premier valeur avec les nombre de 1 a nbElts
		*(tab + i) = i + 1;                        //on affecte i à la variable pointée par chaque adresse du tableau
	}
	return nbElts;
}




int* ajouteElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if ((tab != NULL) && (size != NULL) && (nbElts != NULL)) {
		if (*size > * nbElts) {                   // S'il y a assez de place, pas besoin de realloc on ajoute directement la valeur element au dernier element 
			printf("\n Assez de place");
			*(tab + *nbElts) = element;
			*nbElts = *nbElts + 1;
			return(tab);
		}
		else {
			printf(" \n Plus de place");
			int ajout = TAILLEAJOUT;
			int* tmp = tab;                    //on sauvegarde le pointeur en cas d'échec de la réalloc
			int somme = (*size + ajout);
			tab = (int*)realloc(tab,  somme* (sizeof(int)));
			if (tab != NULL) {                 // On vérifie que la realloc a marché, si oui on peut déplacer tab à l'adresse prévue et modifier les différents compteurs
											  // Cela  permet de ne pas modifier la valeur de tab si la realoc n'a pas fonctionné
				*size = *size + TAILLEAJOUT;
				*(tab + *nbElts) = element;
				*nbElts = *nbElts + 1;
				return(tab);
			}
			else {
				tab = tmp;                      // si la réalloc n'a pas fonctionné, on récupère le pointeur d'origine
				printf("La reallocation n'a pas fonctionne correctement");
				return(NULL);
			}
		}
	}
}









int main() {



	// Déclaration des variables 
	int MyTab1[10];
	int* MyTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 20;
	// Initalisation & affichage de MyTab1
	initTab(MyTab1, 10);
	printf("Tab1 est :");
	afficheTab(MyTab1, 10, 6);


	MyTab2 = (int*)malloc(sizeof(int) * tabSize);    // Allocation dynamique du tableau  
	if (MyTab2 == NULL) {
		printf("Memoire insuffisante");
		exit(0);
	}
	// On initialise MyTab2 avec 20 zéros et on l'affiche
	initTab(MyTab2, nbElts);
	printf(" \n Tab2 est :");
	afficheTab(MyTab2, 20, nbElts);

	// On effectue deux fois la fonction realloc à la suite, et on affiche le tableau à la fin
	printf(" \n Dernier element du tableau :  %d", *(MyTab2 + nbElts - 1));
	ajouteElementDansTableau(MyTab2, &tabSize, &nbElts, 3);
	printf(" \n Dernier element du tableau apres l'ajout : %d", *(MyTab2 + nbElts - 1));
	printf(" \n Il y a %d elements dans le tableau, la taille du tableau est maintenant de %d", nbElts, tabSize);
	ajouteElementDansTableau(MyTab2, &tabSize, &nbElts, 5);
	printf(" \n Dernier element du tableau apres l'ajout : %d", *(MyTab2 + nbElts - 1));
	printf(" \n Il y a %d elements dans le tableau, la taille du tableau est maintenant de %d\n", nbElts, tabSize);
	afficheTab(MyTab2, tabSize, nbElts);
	free(MyTab2); // On n'a plus besoin de MyTab2 donc on libère l'espace en mémoire
}



