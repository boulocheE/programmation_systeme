#include <stdio.h>
#include <ctype.h>


#define TAILLE_MAX 10



int main()
{
	char* tabMois[] = {"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};

	char jour[2];
	char mois[2];
	char annee[4];

	int dateCorrecte = 1;


	


	printf( "%d %s %d", atoi(jour), tabMois[atoi(mois)-1], atoi(annee) );


	return 0;

}



void dateUser ()
{
	char  dateUser[TAILLE_MAX];

	do
	{
		fprint("Rentrez votre date ( au format JJ/MM/AAAA ) : ");
		fgets(dateUser, TAILLE_MAX, stdin);

		if ( strlen(dateUser) == 10 )
		{
			jour[0] = dateUser[0];
			jour[1] = dateUser[1];

			mois[0] = dateUser[3];
			mois[1] = dateUser[4];

			annee[0] = dateUser[6];
			annee[1] = dateUser[7];
			annee[2] = dateUser[8];
			annee[3] = dateUser[9];


			for ( int cpt = 0; cpt < 2; cpt ++ )
				if ( !isdigit(jour[cpt]) ) dateCorrecte = 0;

			for ( int cpt = 0; cpt < 2; cpt ++ )
				if ( !isdigit(mois[cpt]) ) dateCorrecte = 0;

			for ( int cpt = 0; cpt < 4; cpt ++ )
				if ( !isdigit(annee[cpt]) ) dateCorrecte = 0;
		}


	} while ( dateCorrecte(&dateUser) );

}


// tests pour savoir si la date est correcte
int dateCorrecte ( (char[])* date )
{

	if ( strlen(dateUser) == 10 )
		{
			jour[0] = dateUser[0];
			jour[1] = dateUser[1];

			mois[0] = dateUser[3];
			mois[1] = dateUser[4];

			annee[0] = dateUser[6];
			annee[1] = dateUser[7];
			annee[2] = dateUser[8];
			annee[3] = dateUser[9];


			for ( int cpt = 0; cpt < 2; cpt ++ )
				if ( !isdigit(jour[cpt]) ) return 0;

			for ( int cpt = 0; cpt < 2; cpt ++ )
				if ( !isdigit(mois[cpt]) ) return 0;

			for ( int cpt = 0; cpt < 4; cpt ++ )
				if ( !isdigit(annee[cpt]) ) return 0;
		}

	return 0;

}