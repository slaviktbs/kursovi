/*  Програмата изчислява трансфера на Хоман  (Задача 1 от трета презентация),
    като сметките се правят в система СИ (SI)
*/

#include "stdio.h"
#include "math.h"


int main(void)
{
    long unsigned mu, v_par, a_par, s, a_tar;

    mu = 3986004419*10^5;
    a_par = 7000000;
    a_tar = 42164000;

/*
    printf ("Enter the radius of the parking orbit");    // Потребителят въвежда a_par
    scanf ("%f", &a_par);                   

    printf ("Enter the radius of the target orbit");      // Потребителят въвежда a_tar
    scanf ("%f", &a_tar);
*/

    v_par = sqrt(mu/a_par);
    printf ("%u \n", v_par);
 
    return 0;
}