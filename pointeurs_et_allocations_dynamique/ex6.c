#include <stdio.h>

void permute();
void divisionEuclydienne();


int main ()
{
	int a, b;

	int dividende, diviseur, reste, quotient;

	// PARTIE Permutation

	printf( "Valeur de a : " );
	scanf("%d", &a);

	printf( "Valeur de b : " );
	scanf("%d", &b);

	permute(&a, &b);
	printf("Valeur de a : %d\nValeur de b : %d\n", a, b);



	// PARTIE Division Euclydienne

	printf( "Dividende : " );
	scanf("%d", &dividende);

	printf( "Diviseur  : " );
	scanf("%d", &diviseur);

	if ( diviseur == 0 )
	{
		printf("Vous ne pouvez pas diviser un nombre par 0.");

		return 0;
	}


	divisionEuclydienne(dividende, diviseur, &reste, &quotient);
	printf( "Le quotient de %d/%d vaut %d\n", dividende, diviseur, quotient );
	printf( "Le reste    de %d/%d vaut %d\n", dividende, diviseur, reste    );

    printf( "%d * %d + %d = %d\n", quotient, diviseur, reste, dividende );

	return 0;
}


void divisionEuclydienne (int dividende, int diviseur, int* reste, int* quotient )
{
	*quotient = dividende / diviseur;
	*reste    = dividende % diviseur;
}

void permute( int* a, int* b )
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}