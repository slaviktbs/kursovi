/*  Програмата изчислява трансфера на Хоман  (Задача 1 от трета презентация),
    като сметките се правят в система СИ (SI)
*/


#include <stdio.h>
#include <math.h>

int main(void)
{
    double mu, v_par, a_par, v_tr_per, v_tr_apo, v_tar, a_tar, a_tr, delta_v, delta_v_2;

    mu = 398600441900000;
    // a_par = 7000000; 
    // a_tar = 42164000;

    printf ("Enter the radius of the parking orbit");    // Потребителят въвежда a_par
    scanf ("%lf", &a_par);                   

    printf ("Enter the radius of the target orbit");      // Потребителят въвежда a_tar
    scanf ("%lf", &a_tar);

    v_par = sqrt(mu/a_par);

    a_tr = (a_par+a_tar)/2;

    v_tr_per = sqrt(mu*(2/a_par-1/a_tr));

    delta_v = v_tr_per - v_par;

    v_tr_apo = sqrt(mu*(2/a_tar-1/a_tr));

    v_tar = sqrt(mu/a_tar);

    delta_v_2 = v_tar - v_tr_apo;

    printf ("/tdelta v1 = %lf/n", delta_v);

    printf ("/tdelta v2 = %lf/n", delta_v_2);
 
    return 0;
}