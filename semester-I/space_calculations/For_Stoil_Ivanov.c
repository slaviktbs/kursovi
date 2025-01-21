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

#include"math.h"
#include <stdio.h>

int main(void)
{
    double v, s;

    s = 67.0/54.0;
    v = sqrt(s);
    printf ("%lf", v);
 
    return 0;
}
// */