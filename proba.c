#include<stdio.h>

int main() 
{ 
    /*int arr[]={1,2,3,4,5};   //array initialization
    cout<<"The elements are: ";
    for(int i : arr)
    {
    	cout<<i<<" ";
    }
    */

    float a[10]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    float *p;
    p = a;     /*на p се присвояава адреса на началото на а*/
/*така се отпечатват първия, втория
и третия елемент на а*/     // УКАЗАТЕЛИ !!! ЛЕСНО ЗА МАСИВИ ATM...

    printf("%f %f %f\n", *p, *(p+1), *(p+2)); /*това извършва същото но използва а*/
    printf("%f %f %f\n", a[0], a[1], a[2]);  // Същото

    return 0;
}

