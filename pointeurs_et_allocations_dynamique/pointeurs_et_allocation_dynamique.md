> **NOM Prénom :** BOULOCHE Eléonore
>
> **Groupe :** F
>
> **Année :** 2ème

**IUT Le Havre - Programmation Système**

# **Pointeurs et allocation dynamique**
### Compte-rendu du TP 1 : langage C

# Signification des déclarations :

`Exercice 1`

| Déclaration | Signification |
|:-:|---|
|     `int *p;`     | le pointeur `p` stocke l'adresse d'un int                                |
|   `int *a, b;`    | le pointeur `a` stocke l'adresse d'un int, et `b` est un entier          |
|   `int *p[10];`   | le pointeur `p` est un tableau qui stocke l'adresse de 10 entiers        |
|  `int (*p)[10];`  | le pointeur `p` stocke l'adresse d'un tableau de 10 entiers              |
|    `char *p()`    | la fonction `p` renvoie un pointeur de caractère                         |
|   `char (*p)()`   | le pointeur `p` stocke l'adresse d'une fonction qui renvoie un caractère |
| `int (*p)(char a)`| le pointeur `p` stocke l'adresse d'une fonction qui prend en pramètre un caractère et qui renvoie un entier |


# Programmes avec l'utilisation de pointeurs

## **SECTION 1 : Utilisation des pointeurs**
### **a. Programme :**

`Exercice 2`

```c
#include <stdio.h>
int main(){
	int a, b;
	int *p,*q;
	a=12;
	b=2+a/4 ;
	p=&a ;
	printf("*p = %d\t a = %d\n",*p,a);
	*p=*p + 5 ;
	printf("*p = %d\t a = %d\n",*p,a);
	a= a-7;
	printf("*p = %d\t a = %d\n",*p,a);
	q=p ;
	p=&b ;
	printf("*p = %d\t *q = %d\n",*p,*q);
	printf("a = %d\t b = %d\n",a,b);
	q=p ;
	a=a+a ;
	printf("*p = %d\t *q = %d\n",*p,*q);
	printf("a = %d\t b = %d\n",a,b);
	return 0;
}
```

### **b. Schéma mémoire :**
a, b  
*p, *q  
a = 12  
b = 5  
p = adresse de a  
p = 17, a = 17  
a = 10, p = 10  
q = adresse de a  
p = adresse de b  
q = adresse de b  
a = 20  

Donc : a = 10, b = 5, p = 5, q = 5

### **c. Résultat du programme :**
```text
*p = 12		a = 12
*p = 17		a = 17
*p = 10		a = 10
*p = 5		*q = 10
a = 10		b = 5
*p = 5		*q = 5
a = 10		b = 5
```

## **SECTION 2 : Allocation mémoire**

`Exercice 3`

### **a. Programme :**
```c
#include <stdio.h>
#include <stdlib.h>

int a,b ;

void fonc(int c , int *d){
	int e,f;
	int *p,*q;
	p=&e ;
	q =(int*) malloc(sizeof(int));
	printf("L'adresse de a :\t%p\n",&a);
	printf("L'adresse de b :\t%p\n",&b);
	printf("L'adresse de c :\t%p\n",&c);
	printf("L'adresse de d :\t%p\n",&d);
	printf("L'adresse de e :\t%p\n",&e);
	printf("L'adresse de p :\t%p\n",&p);
	printf("L'adresse de q :\t%p\n",&q);
	printf("La valeur de p :\t%p\n",p);
	printf("La valeur de q :\t%p\n",q);
	printf("L'adresse de fonc :\t%p\n",&fonc);

}

int main(){
		fonc(a,&b);
		return 0 ;
}
```

### **b. Analyse et résultat du programme**
- **Malloc**  
Autorise l'accès à une cause mémoire de l'ordinateur. Ainsi, on peut ajouter ou supprimer une ou plusieurs valeurs enregistrées. Donc, nous avons l'adresse générique qu'il contient, et les autres valeurs qui lui ont été ajoutées.  
Si nous avons plusieurs valeurs enregistrées, nous pouvons y accéder comme un tableau.

- **Adresses mémoires** des différentes variables et pointeurs :  
```text
L'adresse de a :        0x55eff23b1014
L'adresse de b :        0x55eff23b1018
L'adresse de c :        0x7fff6789178c
L'adresse de d :        0x7fff67891780
L'adresse de e :        0x7fff67891794
L'adresse de p :        0x7fff67891798
L'adresse de q :        0x7fff678917a0
La valeur de p :        0x7fff67891794
La valeur de q :        0x55eff40452a0
L'adresse de fonc :     0x55eff23ae189
```

- **Emplacement** des différentes variables et pointeurs :  

A l'aide de l'adresse mémoire des variables et pointeurs, nous pouvons définir leur emplacement dans la mémoire.
Ainsi, nous pouvons obtenir le résultat suivant : 

- les variables `a` et `b` sont stockées au même endroit *car elles sont déclarées au début du programme*
- les variables `c` et `d` sont stockées au même endroit *car ce sont les paramètres de la fonction fonc*
- la variable `e` et le pointeur `p` sont stockés au même endroit *car p pointe l'adresse de e*


## **SECTION 3 : Occupation mémoire**  

`Exercice 4`  

### **a. Programme :**
```c
#include <stdio.h>
#include <string.h>
int main(){
	char chaine[]="abcd";
	char c='a';
	printf("Taille de \"a\"       :\t%lu\n", sizeof("a")   );
	printf("Taille de char        :\t%lu\n", sizeof(char)  );
	printf("Taille de int         :\t%lu\n", sizeof(int)   );
	printf("Taille de short       :\t%lu\n", sizeof(short) );
	printf("Taille de long        :\t%lu\n", sizeof(long)  );
	printf("Taille de float       :\t%lu\n", sizeof(float) );
	printf("Taille de double      :\t%lu\n", sizeof(double));
	printf("Taille de 1           :\t%lu\n", sizeof(1)     );
	printf("Taille de 'a'         :\t%lu\n", sizeof('a')   );
	printf("Taille de c           :\t%lu\n", sizeof(c)     );
	printf("Taille de '\\n'       :\t%lu\n", sizeof('\n')  );
	printf("Taille de chaine      :\t%lu\n", sizeof(chaine));
	printf("Longueur de la chaine :\t%lu\n", strlen(chaine));
	return 0;
}
```

### **b. Interprétation de ce programme**

A l'aide de `sizeof`, nous pouvons connaître la taille d'un type, d'une chaîne de caractère, d'un caractère ou d'un entier...  
Ainsi, nous pouvons obtenir le tableau suivant :  
|Type|Taille|
|:-:|---|
|   char ||
|    int ||
|  short ||
|   long ||
|  float ||
| double ||