#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Ingrese valor numerico \n");

    scanf("%i",&a);
    if (a >0) {
        printf("El n�mero %i es positivo \n",a);

    } else
    {
        printf("El n�mero %i es negativo \n",a);
    }


    return 0;
}
/* Esto es una prueba para ver si sincroniza bien.
int main()
{
    int a;
    printf("Ingrese valor numerico \n");

    scanf("%i",&a);
    if (a >0) {
        printf("El n�mero %i es positivo \n",a);

    } else
    {
        printf("El n�mero %i es negativo \n",a);
    }


    return 0;
}

*/
