#include <stdio.h>
#include <string.h>


#define TAILLE_MAX = 20;


int main()
{
	char* s;

	printf("saisir la chaine s :\n")
	fgets(*s, TAILLE_MAX, stdin);

	for ( int cpt = 0; s[cpt] != '\0'; cpt ++ )
	{
		if ( isdigit(s[cpt]) ) printf( "\x1b[31m" );

		printf(s[cpt] + "\033[0m");
	}

}