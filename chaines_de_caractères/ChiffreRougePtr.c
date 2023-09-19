#include <stdio.h>


#define TAILLE_MAX 20;


int main()
{
	char s[TAILLE_MAX];

	printf("saisir la chaine s :\n")
	fgets(s, TAILLE_MAX, stdin);

	for ( int cpt = 0; s[cpt] != '\0'; cpt ++ )
	{
		if ( isdigit(s[cpt]) ) printf( "\x1b[31m%c", s[cpt] );
		else                   printf( "\033[0m%c" , s[cpt] );
	}

	return 0;

}