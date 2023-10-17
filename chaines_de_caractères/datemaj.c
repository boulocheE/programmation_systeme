#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAILLE_MAX 11


void dateUser ( char* jour, char* mois, char* annee )
{
	char dateUser[TAILLE_MAX];
	int dateCorrecte = 1;

	do
	{
		dateCorrecte = 1;

		printf("Rentrez votre date ( au format JJ/MM/AAAA ) : ");
		fgets(dateUser, TAILLE_MAX, stdin);
		
		if ( strlen(dateUser) == 10 )
		{
			jourMoisAnnee( dateUser, jour, mois, annee );

			if ( !eValeurNumerique     (jour, mois, annee ) ) dateCorrecte = 0;
			if ( !valeurSemaineCorrecte(jour, mois         ) ) dateCorrecte = 0;

		} else dateCorrecte = 0;


	} while ( !dateCorrecte );
}


void jourMoisAnnee ( char* dateUser, char* jour, char* mois, char* annee )
{
	jour[0] = dateUser[0];
	jour[1] = dateUser[1];
	jour[2] = '\0';

	mois[0] = dateUser[3];
	mois[1] = dateUser[4];
	mois[3] = '\0';

	annee[0] = dateUser[6];
	annee[1] = dateUser[7];
	annee[2] = dateUser[8];
	annee[3] = dateUser[9];
	annee[4] = '\0';
}


int eValeurNumerique( char* jour, char* mois, char* annee )
{
	for ( int cpt = 0; cpt < 2; cpt ++ ) if ( !isdigit(jour[cpt] ) ) return 0;
	for ( int cpt = 0; cpt < 2; cpt ++ ) if ( !isdigit(mois[cpt] ) ) return 0;
	for ( int cpt = 0; cpt < 4; cpt ++ ) if ( !isdigit(annee[cpt]) ) return 0;

	return 1;
}


int valeurSemaineCorrecte ( char* jour, char* mois )
{
	if ( atoi(jour)  < 1 || atoi(jour) > 31 ) return 0;
	if ( atoi(mois)  < 1 || atoi(mois) > 12 ) return 0;

	return 1;
}


int main()
{
	char* tabMois[] = {"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};

	char jour[3];
	char mois[3];
	char annee[5];

	dateUser( jour, mois, annee );

	printf( "%d %s %d\n", atoi(jour), tabMois[atoi(mois)-1], atoi(annee) );


	return 0;
}