/*  Програмата изчислява трансфера на Хоман  (Задача 1 от трета презентация),
    като сметките се правят в система СИ (SI)
*/

#include <stdio.h>
#include <math.h>

/*
long double myfunc (long double mu, long double a_par)
{
    return sqrtl(mu/a_par);
}
*/

int main(void)
{
    long mu, v_par, a_par, s, a_tar;

    mu = 398600441900000;
    a_par = 7000000;
    a_tar = 42164000;

/*
    printf ("Enter the radius of the parking orbit");    // Потребителят въвежда a_par
    scanf ("%ld", &a_par);                   

    printf ("Enter the radius of the target orbit");      // Потребителят въвежда a_tar
    scanf ("%ld", &a_tar);
*/

    v_par = sqrtl(mu/a_par);
    printf ("%ld \n", v_par);
 
    return 0;
}