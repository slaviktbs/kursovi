/*  The program calculates the Homan transfer (Problem 1 of the third presentation) with calculations made in the SI system.    */


#include <stdio.h>
#include <math.h>

double m_func_par (double a_par)
{
    return a_par*1000;
}

double m_func_tar (double a_tar)
{
    return a_tar*1000;
}

int main(void)
{
    double mu, v_par, a_par, v_tr_per, v_tr_apo, v_tar, a_tar, a_tr, delta_v, delta_v_2;

    mu = 398600441900000;
    // a_par = 7000000; 
    // a_tar = 42164000;

    printf ("\tEnter the radius of the parking orbit (in km): ");    // The user enters a_par 
    scanf ("%lf", &a_par);                   

    printf ("\tEnter the radius of the target orbit (in km): ");      // The user enters a_tar
    scanf ("%lf", &a_tar);

    a_par = m_func_par(a_par);
    a_tar = m_func_tar(a_tar);

    v_par = sqrt(mu/a_par);

    a_tr = (a_par+a_tar)/2;

    v_tr_per = sqrt(mu*(2/a_par-1/a_tr));

    delta_v = v_tr_per - v_par;

    v_tr_apo = sqrt(mu*(2/a_tar-1/a_tr));

    v_tar = sqrt(mu/a_tar);

    delta_v_2 = v_tar - v_tr_apo;

    printf ("\tdelta v1 = %lf m/s\n", delta_v);

    printf ("\tdelta v2 = %lf m/s\n", delta_v_2);
 
    return 0;
}