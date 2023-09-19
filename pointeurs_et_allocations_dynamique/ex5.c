#include <stdio.h>
#include <stdlib.h>             /* à compléter pour malloc() et free */
#include <assert.h>             /* à compléter pour assert() */


int main(){
    int x=1;
    int * y;
    int ** z;
    y = &x ;   /* initialisation du pointeur y */
    z = (int*) malloc(2*sizeof(int));
    assert(z != NULL);
    z[0] = y;
    x = 2;
    z[1] = y;
    printf("*z[0]=%d\t\t*z[1]=%d\n", *z[0], *z[1]);
    free (z);
    return 0;
}

// output : *z[0]=2         *z[1]=2
/*
z peut etre vu comme un tableau de pointeurs,
il stocke l'adresse de x (&x qui est enregistée par y). x change de valeure avant d'assigner z[1] ; cela impacte z[0] et z[1]
car z enregistre une adresse et non une valeure donc la valeure est lue au moment du printf ; dans le printf,
z[0] renvoie l'adresse stockée dans z[0] de x et *z[0] renvoie la valeure stockée à l'adresse.
Dans ce programme ; z[1] == z[0] == &x donc *z[1] == *z[0] == x
*/