/*  Програмата изчислява трансфера на Хоман  (Задача 1 от трета презентация),
    като сметките се правят в система СИ (SI)
*/

/*
#include <stdio.h>
#include <math.h>

int main(void)
{
    float mu, v_par, a_par, s, a_tar;

    mu = 398600441900000;
    a_par = 7000000;
    a_tar = 42164000;
   // v_par = sqr(3);


    printf ("Enter the radius of the parking orbit");    // Потребителят въвежда a_par
    scanf ("%ld", &a_par);                   

    printf ("Enter the radius of the target orbit");      // Потребителят въвежда a_tar
    scanf ("%ld", &a_tar);


    v_par = sqrt(mu/a_par);
    printf ("%f", v_par);
 
    return 0;
}
*/

//---------------------------

// /*
//#include "stdafx.h"

#include <stdio.h>
#include <math.h>

int main(void)
{
    double mu, v_par, a_par, a_tar;

    mu = 398600441900000.0;
    a_par = 7000000.0;
    a_tar = 42164000.0;

    v_par = sqrt(mu/a_par);
    printf ("%lf", v_par);
 
    return 0;
}
// */