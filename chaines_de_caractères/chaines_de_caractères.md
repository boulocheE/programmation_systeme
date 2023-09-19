> **NOM Prénom :** BOULOCHE Eléonore
>
> **Groupe :** F
>
> **Année :** 2ème

**IUT Le Havre - Programmation Système**

# **Chaînes de caractères**
### Compte-rendu du TP 2 : langage C


# Chaînes de caractères - Informations générales :

On peut définir la taille ou laisser le compilateur le définir.
Toujours utilsier sizeof car la taille dépend des systèmes d'exploitation.
Les noms des tableaux sont des pointeurs.

### **a. Programme :**

```c
#include<string.h>
#include <stdlib.h>

#define TAILLECHAINE 12

char s0[10]="numero 1";
char* s1="numero 2";

char* cree_copie_chaine(char*src)
{
	char* copie; //copie est de quel type ?
	copie = (char*) malloc (strlen(src)+1); //expliquer le +1
	strcpy (copie , src); /* copie=destination, src=source*/
	return copie; //retourne-t-on la chaîne copiée ou un pointeur sur celle-ci ?
}
int main()
{
	char s2[TAILLECHAINE];
	char s3[]="numero 3";
	char *pa, *pb, *pc, *pe;
	pa = s1;
	pb = s0;
	strcpy (s2, "A + tard");
	pc = cree_copie_chaine(s0);
	pe = "numero 4";
	free(pc);
	return 0;
}
```

### **b. Chaînes de caractères :**
|  variable  | constant |  taille réservée  |
| :-: | --- | --- |
|  char s0[10]               | oui |  10  |
|  char* s1                  | non, sur une chaîne constante |  9  |
|  char s2[TAILLECHAINE]     | oui |  12  |


**En résumé :**
- k* x[int taille] → constant
- k* x → tableau non constant, je peux changer la taille.  
- pile : variable locales et paramètres des fonctions
- tas : variables globales et malloc

# Parcours d'une chaîne de caractères

## **SECTION 1 : ChiffreRougePtr.c**
-  saisit une ligne de texte tapé au clavier par la fonction fgets
- la parcourt caractère par caractère, identifie au passage les chiffres, et affiche les chiffres en rouge et les autres caractères normalement (voir annexe)

`fgets` : travail sur des fichiers (car **f** devant).  
Trois paramètres : initialise la chaine s, la taille, et la source (le fichier).
Pour lire à partir du clavier : on met `stdin` pour **FILE**.
On déclare une chaîne de maxi 10 caractères, puis stdin. 

Donc : `fgets(char* s, int size (10), FILE* stream (stdin))`

Pour savoir si un caractère est un nombre : **`isdigit`**

boucle sur s de i, tester avec `isdigit`.

