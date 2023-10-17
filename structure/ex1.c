typedef struct {

	char  numJour;
	char  mois [10];
	short annee;

} date;


void afficher ( date date ) {
	printf( "%d %s %hd\n", date.numJour, date.mois, date.annee );
}


void demanderDate( date* pdate) {
	printf( "Donner la date du jour : " );
	scanf( "%d%s%hd", pdate -> numJour, pdate -> mois, pdate -> annee );
}


int main() {
	date d;
	demanderDate(&d);
	afficher( d );
	return 0;
}