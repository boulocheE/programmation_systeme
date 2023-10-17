#include <stdio.h>


#define TAILLE_MAX 20;


char* construireChaineInverse(char*);


int main()
{
	char s[TAILLE_MAX];
	char* sInverse;

	printf("saisir la chaine s :\n")
	fgets(s, TAILLE_MAX, stdin);

	sInverse = construireChaineInverse(&s);

	return 0;

}


char* construireChaineInverse(char* str)
{

	char* tabInverse
	tabInverse = (char*) malloc(strlen(str)+1);


	for ( int cpt = strlen(str); cpt > 0; cpt -- )
		tabInverse[cpt] = str[strlen(str) - cpt];

	tabInverse[strlen(str)+1] = '\0';

	return tabInverse;

}