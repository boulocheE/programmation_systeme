#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 11


int main()
{
	char* tabMois[] = {"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};
	int  tabJours[] = {31       , 28      , 31   , 30    , 31  , 30   , 31      , 31   , 30        , 31      , 30       , 31       };

	char* jour;
	char* mois;
	char* annee;

	char dateUser[TAILLE_MAX];
	int  dateCorrecte = 1;


	do
	{
		dateCorrecte = 1;

		printf("Rentrez votre date ( au format JJ/MM/AAAA ) : ");
		scanf("%s", &dateUser);

		// Utilisation de strtok pour les jours
		if (dateUser != NULL) jour  = strtok(dateUser, "/");
		if (dateUser != NULL) mois  = strtok(NULL, "/");
		if (dateUser != NULL) annee = strtok(NULL, "/");

		if ( jour == NULL || strlen(jour) > 3 || mois == NULL || strlen(mois) > 3 || annee == NULL || strlen(annee) > 5 ) dateCorrecte = 0;


		if ( dateCorrecte )
		{
			for ( int cpt = 0; cpt < 2; cpt ++ ) if ( !isdigit(jour[cpt] ) ) dateCorrecte = 0;
			for ( int cpt = 0; cpt < 2; cpt ++ ) if ( !isdigit(mois[cpt] ) ) dateCorrecte = 0;
			for ( int cpt = 0; cpt < 4; cpt ++ ) if ( !isdigit(annee[cpt]) ) dateCorrecte = 0;
		}

		if ( dateCorrecte && atoi(mois) > 12 ) dateCorrecte = 0;

		if ( dateCorrecte )
		{
			 if ((atoi(annee) % 4 == 0 && atoi(annee) % 100 != 0) || (atoi(annee) % 400 == 0)) tabJours[1] = 29;
			 else                                                                              tabJours[1] = 28;

			 if ( atoi(jour) > tabJours[atoi(mois) - 1] ) dateCorrecte = 0;
		}


	} while ( !dateCorrecte );

	printf( "%d %s %d\n", atoi(jour), tabMois[atoi(mois)-1], atoi(annee) );

	return 0;
}