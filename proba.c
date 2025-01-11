#include<stdio.h>
#include<math.h>

int main() 
{ 
/*
    /*int arr[]={1,2,3,4,5};   //array initialization
    cout<<"The elements are: ";
    for(int i : arr)
    {
    	cout<<i<<" ";
    }
    */

/*
    float a[10]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    float *p;
    p = a;     /*на p се присвояава адреса на началото на а*/
/*така се отпечатват първия, втория
и третия елемент на а    // УКАЗАТЕЛИ !!! ЛЕСНО ЗА МАСИВИ ATM...

    printf("%f %f %f\n", *p, *(p+1), *(p+2)); /*това извършва същото но използва а*/
  //  printf("%f %f %f\n", a[0], a[1], a[2]); */

    float x,y,result_PO, result_SQ;
    scanf("%f",&x);
 //   scanf("%f",&y);

  //  result_PO = powf(x,y);
    result_PO = powf(2,3);
  //  result_SQ = sqrtf(x);
  //  result_SQ = sqrtf(2);
   // result_SQ = log(2);

   // result_PO = 2*2*2;
   // result_SQ = pow(x,y);
   result_SQ = exp(x);

    printf("%f\n%f\n", result_PO,result_SQ);
}

