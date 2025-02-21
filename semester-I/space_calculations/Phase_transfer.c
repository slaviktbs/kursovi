/* The program calculates the phase transfer (Problem 2 of the fourth presentation) with calculations made in the SI system. */


#include <stdio.h>
#include <math.h>

double m_func_orig (double a_orig)
{
    return a_orig*1000;
}

double m_func_phi (double pli)
{
    return pli*60;
}


int main(void)
{
    double mu, delta_v_1, delta_v_2, phi, T, a_orig, a_ph, t_ph, T_ph, v_orig, v_ph_apo, v_ph_per, e;
    int n, choise;

    mu = 398600441999999.0;
    e = 0.00001;
    // a_par = 42164 km;

    a_orig = m_func_orig(a_orig);

    printf ("\tEnter the radius of the parking orbit (in km): ");    // The user enters a_par 
    scanf ("%lf", &a_orig);

    printf ("\tNumber of periods in phase orbit before returning to the initial orbit: ");    // The user enters n
    scanf ("%d", &n);

    printf ("\tPhase difference of the two satellites (in minutes): ");   // The phase transfer 
    scanf ("%lf", &t_ph);

    phi = m_func_phi(phi);   

    printf("\tDepending on whether the goal should be reached or waited for, enter the relevant data: \n");
    printf("\t\t1 - for the goal to be reached \n");
    printf("\t\t2 - for the goal to be waited for \n\t");
    scanf("%d", &choise);

    if(choise == 1)  //reached
    {
        t_ph = (-1.0)*t_ph;
    }

    if(choise == 2)  //waiting
    {
        t_ph = t_ph;
    }

    T = 2*M_PI*sqrt(pow(a_orig,3)/mu);    // The period of the parking orbits

    T_ph = T+t_ph/n;    // The period of the phase orbit

    a_ph = pow(mu*pow(T_ph/(2*M_PI),2),1.0/3);    // The radius of the phase orbit

    v_orig = sqrt(mu/a_orig);

    if(choise==1)
    {
        v_ph_apo = sqrt(mu*(2/(a_ph*(1+e))-1/a_ph));   
    
        delta_v_1 = v_ph_apo - v_orig;
    
        delta_v_2 = (-1.0)*delta_v_1;
    }
    else if(choise==2)
    {
        v_ph_per = sqrt(mu*(2/(a_ph*(1-e))-1/a_ph));

        delta_v_1 = v_ph_per - v_orig;

        delta_v_2 = (-1.0)*delta_v_1;   //НЕ работает как должно, в зависимости от waiting или reached должны быть дельты противоположны по знаку !!!
        
    }

    printf ("\tdelta v1 = %lf m/s\n", delta_v_1);

    printf ("\tdelta v2 = %lf m/s\n", delta_v_2);   

    return 0;
}