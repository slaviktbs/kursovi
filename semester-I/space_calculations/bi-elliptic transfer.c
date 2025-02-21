/* The program calculates the bi-elliptic transfer (Problem 1 of the fourth presentation) with calculations made in the SI system. */


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
    double mu, v_par, a_par, v_tr_per_1, v_tr_per_2, v_tr_apo_1, v_tr_apo_2, v_tar, a_tar, a_tr_1, a_tr_2, delta_v_1, delta_v_2, delta_v_3, f;

    mu = 398600441999999.0;
    // a_par = 7000 km; 
    // a_tar = 105000 km;
    // f = 2;

    printf ("\tEnter the radius of the parking orbit (in km): ");    // The user enters a_par 
    scanf ("%lf", &a_par);                   

    printf ("\tEnter the radius of the target orbit (in km): ");      // The user enters a_tar
    scanf ("%lf", &a_tar);

    printf ("\tEnter the transfer orbit factor: ");      // The user enters f
    scanf ("%lf", &f);

    a_par = m_func_par(a_par);
    a_tar = m_func_tar(a_tar);

    v_par = sqrt(mu/a_par);

    a_tr_1 = (a_tar*f + a_par)/2;

    v_tr_per_1 = sqrt(mu*(2/a_par-1/a_tr_1));

    delta_v_1 = v_tr_per_1 - v_par;

    v_tr_apo_1 = sqrt(mu*(2/(2*a_tr_1-a_par)-1/a_tr_1));

    a_tr_2 =  (a_tar - a_par + 2*a_tr_1)/2;  
    
    v_tr_apo_2 = sqrt(mu*(2/(2*a_tr_2-a_tar)-1/a_tr_2));

    delta_v_2 = v_tr_apo_2 - v_tr_apo_1;

    v_tr_per_2 = sqrt(mu*(2/a_tar-1/a_tr_2));

    v_tar = sqrt(mu/a_tar);

    delta_v_3 = v_tar - v_tr_per_2;

    printf ("\tdelta v1 = %lf m/s\n", delta_v_1);

    printf ("\tdelta v2 = %lf m/s\n", delta_v_2);

    printf ("\tdelta v3 = %lf m/s\n", delta_v_3);
    
    return 0;
}