/*
    The program calculates the distance, travel time, and fuel consumption to travel from Earth to the Moon/Mars, with the SpaceX Starship rocket, using user-entered data:
        1) destination
        2) mass of the payload
*/

#include <stdio.h>
/*#include "stdafx.h"
#include "math.h"
*/
#include <math.h>

float mass_func (float M_Starship, float mass)
    {
        return M_Starship + mass;
    }

union Union_ALL
  {
    float y;
  };

int main(void)
{
    union Union_ALL union_pointer;
    int first_choose, details;

    float mass, y, M_Starship, R_Moon, R_Mars, Lambda, g, Ro, k, S, V_1, v_space, m_space, m_landing, M_Moon, M_Mars, G, S_all, S_space, S_atmos, S_landing, M_Eath, t_all, t_atmos, t_space, t_landing, t_all_min, t_all_hour, fuel_all, fuel_atmos, fuel_space, fuel_landing, *u_ATMOS, *u_SPACE, *u_LANDING, *u_ALL;
    const float R_Eath = 6378000;;

    float ATPOSPHERE[3];
    float LANDING[3];
    float SPACE[3];
    float ALL[3];

    printf ("Welcome to interplanetary travel ! \n\n");

    printf ("Choose the destination: \n");
    printf ("\t 1 - Moon \n");
    printf ("\t 2 - Mars \n\n");
    for (int i=0; i<=2; i++)
   {
      
      printf ("To chouse press 1 or 2 \n");
      scanf ("%d", &first_choose);
      if (first_choose != 0){i++;}

      printf ("\nEnter the mass of the product you want to send on the destination (in kg): \n");
      scanf ("%f", &mass);
      if (mass != 0){i++;}
   }

    y = 0;
    S_atmos = 150000;
    S_landing = 40000;
    R_Moon = 1737000;
    R_Mars = 3390000;
    M_Starship = 4000000;
    V_1 = 7910;
    Lambda = 50200000;
  //G = 6.67430*10^-11;
  //G = 0.0000000000667430  
    G = 6.6743E-11;   // !! CAN CHANGE VALUE !!
 // G = 66743*0.0001;
 // G = 66743*10^-15;
    g = 98E-1;
    M_Eath = 59722*10^20;
    M_Moon = 7.35E22;
  //M_Mars = 6.417E23;
    M_Mars = 6417*10^20;
//  Ro = 1.2754;  // плотность воздуха
    Ro = 12754*0.0001;
    k = 0.5;  // Коэфициент сопротивления формы грубо
    S = 3; //площадь поперечного сечения !! очень грубо пока !!!
 // v_space = 1444.44;  // Скоростта на ракета в космоса
    v_space = 144444*0.01;


// Calculating the first part of the trip: the atmosphere

    if (first_choose == 1)  // The user has chosen the Moon as their destination
    {
        t_atmos = (2*S_atmos)/V_1;

        fuel_atmos=(mass_func(M_Starship, mass)*g*R_Eath-0.5*mass_func(M_Starship, mass)*(V_1*V_1)-mass_func(M_Starship, mass)*G*M_Eath-0.5*Ro*k*S*(V_1*V_1)*S_atmos)/Lambda;
    }

    else if (first_choose == 2)  // The user has chosen the Mars as their destination
    {
       t_atmos = (2*S_atmos)/V_1;

       fuel_atmos=(mass_func(M_Starship, mass)*g*R_Eath-0.5*mass_func(M_Starship, mass)*(V_1*V_1)-mass_func(M_Starship, mass)*G*M_Eath-0.5*Ro*k*S*(V_1*V_1)*S_atmos)/Lambda;
    }

    ATPOSPHERE[0] = S_atmos;
    ATPOSPHERE[1] = t_atmos;
    ATPOSPHERE[2] = fuel_atmos;

// Calculating the second part of the trip: space

    if (first_choose == 1)
    {
        S_space = 384400000 - S_atmos - S_landing - R_Eath - 1737400;

        t_space = S_space/v_space;

        m_space = mass_func(M_Starship, mass) - fuel_atmos;

       fuel_space = (m_space*g*(R_Eath+S_atmos)+0.5*m_space*(V_1*V_1)-0.5*m_space*(v_space*v_space))/(Lambda);
    }

    else if (first_choose == 2)
    {
        S_space = 225000000000 - S_atmos - S_landing - R_Eath - 3389000;

        t_space = S_space/v_space;

        m_space = mass_func(M_Starship, mass) - fuel_atmos;

       fuel_space = (m_space*g*(R_Eath+S_atmos)+0.5*m_space*(V_1*V_1)-0.5*m_space*(v_space*v_space))/(Lambda);      
    }

    SPACE[0] = S_space;
    SPACE[1] = t_space;
    SPACE[2] = fuel_space;


// Calculating the third part of the trip: space, near the second planet so that the rocket must slow down to stop

    if (first_choose == 1)
    {
        t_landing = (2*S_landing)/v_space;

        m_landing = mass_func(M_Starship, mass) - fuel_space;

        fuel_landing = ((m_landing*M_Moon*G)/R_Moon - 0.5*m_landing*(v_space*v_space) + m_landing*M_Moon*G/(R_Moon+S_landing))/Lambda;
        
        //fuel_landing = (0,5*m_landing*(v_space*v_space) + m_landing*M_Moon*G/(R_Moon+S_landing))/Lambda;
    }

    else if (first_choose == 2)
    {
        t_landing = (2*S_landing)/v_space;

    //  fuel_landing = ((m_landing*M_Mars*G)/R_Mars - 0.5*m_landing*(v_space*v_space) + m_landing*M_Mars*G/(R_Mars+S_landing))/Lambda;;
        
    //  fuel_landing = (0,5*m_landing*(v_space*v_space) + m_landing*M_Moon*G/(R_Moon+S_landing))/Lambda;
        fuel_landing = 5;
    }

    LANDING[0] = S_landing;
    LANDING[1] = t_landing;
    LANDING[2] = fuel_landing;

    S_all = S_atmos + S_space + S_landing;
    t_all = t_atmos + t_space + t_landing;
    fuel_all = fuel_atmos + fuel_space + fuel_landing;

    ALL[0] = S_all;
    ALL[1] = t_all;
    ALL[2] = fuel_all;


  for (int i=0; i<=2; i++)
  {
    if (i==0){
      union_pointer.y = S_all;
      printf("\n\t The total distance of the flight is: %f  meters \n",union_pointer.y);
    }

    else if (i==1){
      union_pointer.y = t_all;
      printf("\t The total time of the flight is: %f seconds\n",union_pointer.y);
    }
    else if (i==2){
      union_pointer.y  = fuel_all;
      printf("\t The fuel consumption of the flight is: %f  kilograms of liquid methane \n",union_pointer.y);
    }
  }  

    u_ATMOS = ATPOSPHERE;
    u_SPACE = SPACE;
    u_LANDING = LANDING;
    u_ALL = ALL;

    printf ("\n\t The total distance of the flight is: %f  meters \n", *u_ALL);
    
    printf ("\t The total time of the flight is: %f seconds\n", *(u_ALL+1));

    printf ("\t The fuel consumption of the flight is: %f  kilograms of liquid methane \n", *(u_ALL+2));

    printf("\nIf you want to see a details, press 1 \n");
    printf("If you don't want to, press 2 \n");
    scanf ("%d", &details);

    if (details == 1)
    {

// Лучше сделать указател като параметр на функция, преподу такое нравиться !!

        printf ("\nThe journey is divided into 3 parts: atmosphere, space and landing \n\n");

        printf("About atmosphere : \n");

        printf ("\t The distance of the flight is: %f meters \n \t The time of the flight is: %f seconds \n \t The fuel consumption is: %f kilograms \n", *u_ATMOS, *(u_ATMOS+1), *(u_ATMOS+2));

        printf("About space : \n");
        printf ("\t The distance of the flight is: %f meters \n \t The time of the flight is: %f seconds \n \t The fuel consumption is: %f kilograms \n", *u_SPACE, *(u_SPACE+1), *(u_SPACE+2));

        printf("About landing : \n");
        printf ("\t The distance of the flight is: %f meters \n \t The time of the flight is: %f seconds \n \t The fuel consumption is: %f kilograms \n\n", *u_LANDING, *(u_LANDING+1), *(u_LANDING+2));

    }
    else if (details == 2)
    {
        printf ("\nBye bue \n\n");
    }

    return 0;
}

/*

    Добавить СТЕПЕНЬ для скоростей (для math.h)



        ПРОВЕРИТЬ, КОНЕЧНО, ФОРМУЛЫ И РАСЧЕТЫ
        ПРОСЧИТАТЬ ВСЕ НА БУМАГЕ -> ПОЛУЧИТЬ ЧИСЛА (вычисления на калькуляторе, лучше на  MAPLE), СРАВНИТЬ С ЧИСЛАМИ В ПРОГРАММЕ
      
        СДЕЛАТЬ КОММЕНТАРИИ НА АНГЛИЙСКОМ



    
    Также лучше выдавать время в ч и мин, что удобнее -->> изменить немного код...

*/