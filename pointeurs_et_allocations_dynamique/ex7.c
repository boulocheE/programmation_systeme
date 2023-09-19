// Exercice 7 : tableaux dynamiques
// Écrire un prgramme qui permet de :
// Créer un tableau d'entiers de taille  n1 > 2, n1 est  donnée par l'utilisateur.

// Initialiser ce tableau avec des valeurs aléatoires comprises entre 0 et 50.
// Trier ce  tableau par ordre croissant en utilisant la fonction qsort du 
// c (void qsort(const void *tab,size_t n, size_t taille, int (*cmp)(const void *p1, const void *p2))).

// Il faut écrire 3 fonctions : une fonction generer qui permet initialiser le tableau,
// une fonction afficher qui permet d'afficher le tableau et une fonction trier qui permet de trier le tableau.



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialiser(int*, int);
void afficher   (int*, int);
void trier      (int*, int);

int main ()
{

	int  tailleUser;
	int* tableau;

	srand(time(NULL));


	do
	{
		printf( "Taille du tableau (strictement supérieure à 2) :\n" );
		scanf( "%d", &tailleUser );
	} while ( tailleUser <= 2 );


	initialiser( tableau, tailleUser );
	afficher   ( tableau, tailleUser );
	trier      ( tableau, tailleUser );
	afficher   ( tableau, tailleUser );

	free(tableau);

	return 0;
}


void initialiser ( int* tab, int tailleTab)
{

	tab = malloc(tailleTab * sizeof(int));

	for ( int cpt = 0; cpt < tailleTab; cpt ++ )
		*( tab + cpt ) = rand() % 50;
		// tab[cpt] = rand() % 50;	OPTION 2

}


int compare (const void *pElem1, const void * pElem2)
{
	const int a = *((int*)pElem1);
	const int b = *((int*)pElem2);

	if ( a>b ) return 1;
	if ( a<b ) return -1;

	return 0;   //a == b
}


void trier ( int* tab, int taille ) { qsort(tab, taille, sizeof(int), compare); }

void afficher ( int* tab, int taille )
{

	printf( "Tableau : [" );

	for ( int cpt = 0; cpt < taille - 1; cpt ++ )
		printf( "%d; ", *( tab + cpt ) );

	printf( "%d]\n" *( tab + taille - 1 ));

}