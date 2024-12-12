// Програмата изчислява трансфера на Хоман  (Задача 1 от трета презентация), като сметките се правят в система СИ (SI)

#include <stdio.h>
#include <math.h>


int main(void)
{
    double v_par, mu, a_par, s;
    long a_tar;

    mu = 3986004419*10^5;
    a_par = 7*10^6;
    a_tar = 42164*10^3;

/*
    printf ("Enter the ... ");
    scanf ("%", &);                    // Потребителят въвежда a_par

    printf ("Enter the ... ");
    scanf ("%", &);                    // Потребителят въвежда a_tar
*/
    s = mu/a_par;
    v_par = sqrt(s);
    printf ("%lf", v_par);



    return 0;
}