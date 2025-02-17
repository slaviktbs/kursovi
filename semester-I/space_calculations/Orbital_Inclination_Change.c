/* The program calculates the orbital inclination change (Problem 2 of the third presentation) with calculations made in the SI system.  */

#include <stdio.h>
#include <math.h>

double m_func_par (double a)
{
    return a*1000;
}

double deg_to_rad (double alpha)
{
    return alpha*(3.14/180);
}

int main(void)
{
    double delta_v_norm, delta_v_neg, delta_V, v_orig, alpha, a, mu;

    mu = 398600441999999.0;
    // a = 7200 km;
    // alpha = 30 degrees;

    printf ("\tEnter the radius of the parking orbit (in km): ");    // The user enters a_par 
    scanf ("%lf", &a);

    printf ("\tEnter the angle setting the desired inclination change (in degrees): ");    // The user enters alpha
    scanf ("%lf", &alpha);

    a = m_func_par(a);
    alpha = deg_to_rad(alpha);

    v_orig = sqrt(mu/a);

    delta_v_norm = v_orig*sin(alpha);

    delta_v_neg = v_orig*(cos(alpha)-1);

    delta_V = sqrt(delta_v_norm*delta_v_norm + delta_v_neg*delta_v_neg);

    printf ("\tDelta V = %lf m/s\n", delta_V);
    
    printf ("\tThe normal component = %lf m/s\n", delta_v_norm);

    printf ("\tThe negative component = %lf m/s\n", delta_v_neg);
    
    return 0;
}