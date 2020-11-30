#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "Header.h"
#define TAILLEINITIALE 10



//1

TABLEAU NewArray() {
	TABLEAU tableau;
	tableau.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));    //on allloue une taille de TAILLEINITIALE * taille d'un entier en mémoire
	if (tableau.elt != NULL) {                                  // si malloc a fonctionné on initialise le tableau avec des 0
		for (int i = 0; i < TAILLEINITIALE; i++) {
			*(tableau.elt + i) = 0;
		}
	}
	tableau.size = TAILLEINITIALE;
	tableau.eltsCounts = 0;
	
	return tableau;                                          //on return notre tableau

}


//2
int incrementArraySize(TABLEAU* tab, int incrementValue) {
	int* tpp = tab->elt;                                                                // sauvegarde du pointeur actuel
	tab->elt  = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));   //on réalloue de la mémoire 
	if (tab->elt == NULL) {                                                             // si cela echoue on renvoit -1                         
		tab->elt = tpp;                                                                 // restitution du pointeur précédent
		return -1;
	}
	else {
		tab->size += incrementValue;     //on met à jour la nouvelle taille du tableau et on renvoie la taille                                                
		return tab->size;
	}
}


//3

int setElement(TABLEAU* tab, int pos, int element) {
	if ((pos < 0) || (tab == NULL)) return 0;               //cas d'erreur
 	if (pos <= tab->size) {                                 //le cas ou la taille est assez grande pour inserer notre element a la position pos
		if(*(tab->elt + pos-1) ==0){                         //l'element est inserer a la position pos
			tab->eltsCounts += 1;
		}
		*(tab->elt + pos-1) = element;                     //l'element est inserer a la position pos 
		return pos;
		}
	else {                                                  //le cas ou la taille n'est pas assez grande pour inserer notre element a la position pos
		int anciennetaille = tab->size;
		if (incrementArraySize(tab, pos - tab->size) == -1) {    // on agrandit le tableau et si l'agrandissement du tableau échoue, on retourne 0
			return 0;
		}
		for (int i = 0; i < pos-anciennetaille; i++) {      //remplit les nouvelles cases du tableau de 0
			*(tab->elt + anciennetaille + i) = 0;
		}
		*(tab->elt + pos - 1) = element;                  //agrandissement réussi, on insere le nouvel element et on augmente le nombre d'éléments
		tab->eltsCounts++;                                // la taille est mis à jour dans la fonction incrementArraySize
		    
		return pos;
		}
	}



//4

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if ((startPos >0) && (endPos>0) && (tab != NULL) && (endPos <= tab->size)) {
		if (startPos < endPos) {                                  //si l'utilisateur a entré une valeur de départ< valeur d'arrivée on ne change rien
			for (int i = startPos-1; i <= endPos-1; i++) {       //on affiche les elements du tableau de startPos-1 à endPos ( le premier element est a la position 1)
				printf("%d ", *(tab->elt + i));
			}
		}

		else {                                                   //si l'utilisateur a entré une valeur de départ> valeur d'arrivée on inverse les deux valeurs
			int tmp;
			tmp = startPos;
			startPos = endPos;
			endPos = tmp;
			for (int i = startPos-1; i <= endPos-1; i++) {       //on affiche les elements du tableau de startPos-1 à endPos ( le premier element est a la position 1)
				printf("%d ", *(tab->elt + i));
			}

		}
		return 0;
	}
	else {                         //erreur si position plus petite que 1 ou en dehors de la taille du tableau
		return -1;
	}
}


//5
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if ((startPos > 0) && (endPos > 0) && (tab != NULL) && (endPos <= tab->size)) {
		if (startPos > endPos) {                                // si l'utilisateur a entré une valeur de départ> valeur d'arrivée, on inverse les deux pour ne pas renvoyer d'erreur
			int tmp;
			tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		int nbElemSupp = endPos - startPos + 1;                    //on calcule le nombre d'éléments à supprimer
			for (int i = startPos - 1; i <= endPos - 1; i++) {
				if (*(tab->elt + i) != 0) {                         // si on supprime un élément différent de 0  
					tab->eltsCounts = tab->eltsCounts - 1;        // on a supprimé un élement du tableau donc on décrémente tab.eltsCount
				}
			}
			for (int i = 0; i < tab->size - endPos; i++) {
				// printf(" On supprime %d", *(tab->elt + startPos - 1 + i));
				*(tab->elt + startPos - 1 + i) = *(tab->elt + startPos - 1 + nbElemSupp + i); // on decale les valeurs de nbElementsSuppr vers la gauche
		}
		int* tmp2 = tab->elt;                                                                   // sauvegarde du pointeur actuel
		tab->elt = (int*)realloc(tab->elt, ((tab->size -nbElemSupp) * sizeof(int)));            //on realloue la memoire
		if (tab->elt == NULL) {                    // échec de la réallocatio
			
			tab->elt = tmp2;                      // restitution du pointeur précédent
			return -1;
		}
		else {
			tab->size -=nbElemSupp;               // on met la taille à jour
		}
		return tab->size;

	}
	else {                        //erreur si position négative ou en dehors de la taille du tableau
		return -1;
	}

}
			






int main(){
	TABLEAU tab = NewArray();
	printf("Le nombre d'elements dans le tableau est %d :", tab.eltsCounts); //on affiche le nombre d'element, c'est a dire de valeurs non nulles dans le tableau
	printf("\nTaille : %d\n", tab.size); //on affiche la taille du tableau
	printf("Tableau : \n");
	displayElements(&tab, 1, 10); //On affiche tout le tableau initial
	setElement(&tab, 1, 5);
	setElement(&tab, 2, 7);
	setElement(&tab, 13, 8); // Le tableau est initialement de taille 10 donc il est agrandi pour placer 8 à la position 13( en appelant la fonction incrementArraySize dans la fonction setElement
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCounts);
	printf("\nTaille : %d\n", tab.size);
	printf("Tableau : \n");
	displayElements(&tab, 1, tab.size); // On a ajouté les 3 valeurs et on affiche le tableau
	deleteElements(&tab, 10, 13);
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCounts);
	printf("\nTaille : %d\n", tab.size);
	printf("Tableau : \n");
	displayElements(&tab, 1, tab.size);
	setElement(&tab, 12, 4);
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCounts);
	printf("\nTaille : %d\n", tab.size);
	printf("Tableau : \n");
	displayElements(&tab, 1, tab.size);
}