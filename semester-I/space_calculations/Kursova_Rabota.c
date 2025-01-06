/*
    Програмата пресмята расхода на горивото, време за пътуване от Земя до Луна/Марс, със ракета Starship на кампанията SpaceX, като исползва дани въведени от потребител: 
        дистинацията (destination)
        масата на товара (mass)
    ** също така използва даните за времето в космодром "НАЗВАНИЕ" (взима се от интернет, съхранява се във файла и се използва от програмата)
        
        
*/

#include <stdio.h>
#include<math.h>

float mass_func (float M_Starship, float mass)
    {
        return M_Starship + mass;
    }

int main(void)
{
    int first_choose, details;

    float mass, M_Starship, R_Moon, R_Mars, Lambda, g, Ro, k, S, V_1, v_space, m_space, m_landing, M_Moon, M_Mars, G, S_all, S_space, S_atmos, S_landing, M_Eath, t_all, t_atmos, t_space, t_landing, t_all_min, t_all_hour, fuel_all, fuel_atmos, fuel_space, fuel_landing, *u_ATMOS, *u_SPACE, *u_LANDING;
    const float R_Eath = 6378000;;

    float ATPOSPHERE[3];
    float LANDING[3];
    float SPACE[3];

    printf ("Welcome to interplanetary travel ! \n\n");

    printf ("Choose the destination: \n");
    printf ("\t 1 - Moon \n");
    printf ("\t 2 - Mars \n\n");
    printf ("To chouse press 1 or 2 \n");
    scanf ("%d", &first_choose);


    printf ("\nEnter the mass of the product you want to send on the destination (in kg): \n");
    scanf ("%f", &mass);


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
    g = 98E-1;
 // M_Eath = 5.9722*10^24;
    M_Eath = 59722*10^20;
    M_Moon = 7.35E22;
    M_Mars = 6.417E23;
    Ro = 1.2754;  // плотность воздуха
    k = 0.5;  // Коэфициент сопротивления формы грубо
    S = 3; //площадь поперечного сечения !! очень грубо пока !!!
    v_space = 1444.44;  // Скоростта на ракета в космоса

// Пресмятане на първата част от пътя: атмосферата

    if (first_choose == 1)  // Потребителя е избрал за дестинация Луната
    {
        t_atmos = (2*S_atmos)/V_1;

        fuel_atmos=(mass_func(M_Starship, mass)*g*R_Eath-0.5*mass_func(M_Starship, mass)*(V_1*V_1)-mass_func(M_Starship, mass)*G*M_Eath-0.5*Ro*k*S*(V_1*V_1)*S_atmos)/Lambda;
        //fuel_atmos=5;
    }

    else if (first_choose == 2)  // Потребителя е избрал за дестинация Марс
    {
       t_atmos = (2*S_atmos)/V_1;

       fuel_atmos=(mass_func(M_Starship, mass)*g*R_Eath-0.5*mass_func(M_Starship, mass)*(V_1*V_1)-mass_func(M_Starship, mass)*G*M_Eath-0.5*Ro*k*S*(V_1*V_1)*S_atmos)/Lambda;
        //fuel_atmos=6;
    }

    ATPOSPHERE[0] = S_atmos;
    ATPOSPHERE[1] = t_atmos;
    ATPOSPHERE[2] = fuel_atmos;


// Пресмятане на втората част от пътя: космоса, далеч от планетите

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

        m_space = mass_func(M_Starship, mass) - fuel_atmos;     // 1590080

       fuel_space = (m_space*g*(R_Eath+S_atmos)+0.5*m_space*(V_1*V_1)-0.5*m_space*(v_space*v_space))/(Lambda);      

    }

    SPACE[0] = S_space;
    SPACE[1] = t_space;
    SPACE[2] = fuel_space;


// Пресмятане на третата част от пътя: космоса, близо до втората планета така, 
// че ракетата трябва да се забавя, за да спре


    if (first_choose == 1)
    {
        t_landing = (2*S_landing)/v_space;

        m_landing = mass_func(M_Starship, mass) - fuel_space;

        fuel_landing = ((m_landing*M_Moon*G)/R_Moon - 0,5*m_landing*(v_space*v_space) + m_landing*M_Moon*G/(R_Moon+S_landing))/Lambda;
        
        //fuel_landing = (0,5*m_landing*(v_space*v_space) + m_landing*M_Moon*G/(R_Moon+S_landing))/Lambda;
    }

    else if (first_choose == 2)
    {
        t_landing = (2*S_landing)/v_space;

        fuel_landing = ((m_landing*M_Mars*G)/R_Mars - 0,5*m_landing*(v_space*v_space) + m_landing*M_Mars*G/(R_Mars+S_landing))/Lambda;;
        
        //fuel_landing = (0,5*m_landing*(v_space*v_space) + m_landing*M_Moon*G/(R_Moon+S_landing))/Lambda;
    }

    LANDING[0] = S_landing;
    LANDING[1] = t_landing;
    LANDING[2] = fuel_landing;

    u_ATMOS = ATPOSPHERE;
    u_SPACE = SPACE;
    u_LANDING = LANDING;

    S_all = (S_atmos + S_space + S_landing);

    t_all = t_atmos + t_space + t_landing;

    fuel_all = fuel_atmos + fuel_space + fuel_landing;

/*
    printf("%f", fuel_landing);
    printf ("\n\n \t The total distance of the flight is: %f  kilometers \n", S_all);

 //   printf ("t_all = %f \n", t_all);

  //printf ("\t The total time of the flight is: %u  hours   %f  minutes \n", t_all_hour, t_all_min);

    printf ("\t The fuel consumption of the flight is: %f  kilograms of liquid methane \n", fuel_all);

    printf ("atmos: %f \n", t_atmos);
    printf ("space: %f \n", t_space);
    printf ("landing: %f \n", t_landing);
*/
    printf("\nIf you want to see a details, press 1 \n");
    printf("If you don't want to, press 2 \n");
    scanf ("%d", &details);

    if (details == 1)
    {
/*
        printf("%f \n\n", ATPOSPHERE[0]);
        printf("%f \n\n", ATPOSPHERE[1]);
        printf("%f \n\n", ATPOSPHERE[2]);
*/
        printf("\t %f \n\n", *u_ATMOS);
        printf("\t %f \n\n", *(u_ATMOS+1));
        printf("\t %f \n\n", *(u_ATMOS+2));

        printf("Atmosphere \n");
        printf("%f \n", S_atmos);
        printf("%f \n", t_atmos);
        printf("%f \n\n", fuel_atmos);
/*        
        printf("%f \n\n", SPACE[0]);
        printf("%f \n\n", SPACE[1]);
        printf("%f \n\n", SPACE[2]);
*/      
        printf("\t %f \n\n", *u_SPACE);
        printf("\t %f \n\n", *(u_SPACE+1));
        printf("\t %f \n\n", *(u_SPACE+2));

        printf("Space \n");
        printf("%f \n", S_space);
        printf("%f \n", t_space);
        printf("%f \n\n", fuel_space);  
/*
         printf("%f \n\n", LANDING[0]);
        printf("%f \n\n", LANDING[1]);
        printf("%f \n\n", LANDING[2]);
*/
        printf("\t %f \n\n", *u_LANDING);
        printf("\t %f \n\n", *(u_LANDING+1));
        printf("\t %f \n\n", *(u_LANDING+2));

        printf("Landing \n");
        printf("%f \n", S_landing);
        printf("%f \n", t_landing);
        printf("%f \n\n", fuel_landing);

        /*
        printf ("\n\n The journey is divided into 3 parts: atmosphere, space and landing \n\n ");

        printf("About atmosphere : \n");
        printf ("\t The distance of the flight in atmosphere is: %f /n/n/r");

        //printf ("\t The distance of the flight in atmosphere is: %f meters \n \t The time of the flight in atmosphere is: %f seconds \n \t The fuel consumption per atmosphere is: %f kilograms \n", ATPOSPHERE[0], ATPOSPHERE[1], ATPOSPHERE[2]);

        printf("About space : \n");
        printf ("\t The distance of the flight in space is: %f meters \n, \t The time of the flight in space is: %f seconds \n, \t The fuel consumption per space is: %f kilograms \n\n", SPACE[0], SPACE[1], SPACE[2]);


        /*
        printf ("\t The time of the flight in space is: %u seconds \n", t_space);
        printf ("\t The fuel consumption per space is: %u kilograms \n", fuel_space);

        printf("About landing : \n");
        printf ("\t The time of the flight in landing is: %u seconds \n", t_landing);
        printf ("\t The fuel consumption per landing is: %u kilograms \n", fuel_landing);
*/
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



    total time - примерно 36 дней, что очень много -->> проверить time_... 
        ДОЛЖНО БЫТЬ ПРИМЕРНО 3 ДНЯ ! (примерно 290 000 секунд)
    Также лучше выдавать время в ч и мин, что удобнее -->> изменить немного код...

    total fuel - 562 млн тонн, что очень много -->> проверить fuel_...
    

    total time и total fuel неправильны не из-за неправильных рассчетов по физике,
    а из-за неправильных типов переменных "can change value" !!!Разобраться с типом переменных


    то, что НУЖНО ДОДЕЛАТЬ:
        функция 
            m = mass+M_Starship
        массив
            atmosphere:
                time
                fuel
                s
            space:
            ...
            landing
            ... 
        


*/