/*
    Програмата пресмята расхода на горивото, време за пътуване от Земя до Луна/Марс
    от космодром "НАЗВАНИЕТО",
    като исползва дани въведени от потребител: 
        дистинацията (destination)
        масата на товара (mass)
    също така използва даните за времето във космодром "НАЗВАНИЕ" (взима се от интернет, съхранява се във файла и се използва от програмата)
        
        
*/
#include <stdio.h>


int main(void)
{
    int first_choose second_choose;
    float mass, S_all, S_atmos, S_space, S_landing;
    float t_all, t_atmos, t_space, t_landing;
    float fuel_all, fuel_atmos, fuel_space, fuel_landing;
    char Moon, Mars;
    printf ("Choose the destination: Moon (1) or Mars (2) \n");
    printf ("Click 1 or 2 to choose it \n");
    scanf ("%d", &first_choose);
    printf ("You have chosen: %d", first_choose);


//    printf ("Choose the cosmodrome: \n");
/*  тук трябва да се добави списъка от файла за избор
    след което да се взме от интернет данните за времето в дадения ден и час и по-нататък да се съобразява с тях,
    като съпротивление на въздух и тн 
*/ 
/*  printf ("Click from 1 to 2 to choose it \n");
    scanf("%d", &second_choose);
    printf ("You have chosen: %d", second_choose);
*/


    printf ("Enter the mass of the product in kg: \n");
    scanf ("%lf", &mass);
    printf ("Your entered mass: %lf", mass);


/*
    Започва да се пресмята време за пътуване.


    От кинематика (без отчитане на съпротивление на въздуха) знаем, че за да се изкачи на височина h
*/
    S_all = S_atmos + S_spac + S_landing;
    t_all = t_atmos + t_space + t_landing;
    fuel_all = fuel_atmos + fuel_space + fuel_landing;
    if (first_choose == 1)
    {
        S_atmos = 
        S_space = 
        S_landing =
    }
    
}