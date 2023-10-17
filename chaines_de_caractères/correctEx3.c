invtexte = (char *) malloc(sizeof(char) * TAILLECHAINE);
printf("entrez une chaîne de caractères : \n");
fgets(texte, TAILLECHAINE, stdin);
printf("%s\n", texte);
puts("\n la chaîen inverse : ");
invtexte = construireChaineInverse(texte);

for ( i = 0; i < strlen(texte); i++ )
    putchar(invtexte[i]);

putchar('\n');
return 0;



char*.....
char* inverserChaine;
int i; 
inverserChaine = (char*) malloc(sizeof(char)*strlen(str));
for (i = 0; i<strlen(str))
for (i)