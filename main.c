#include <stdio.h>
#include <math.h>
float fun(float x)
{
return(x*x*x-4*x-9);
}
void bisection(float*x,float a,float b,int*itr)
{
*x=(a+b)/2;
++(*itr);
printf("iteration number %3d x=%7.5f\n",*itr,*x);
}
int main()
{
int itr=0,max_itr;
float x,a,b,all_error,x1;
printf("/n enter the values of a,b,allowed error & maximum iteration: \n");
scanf("%f%f%f%d",&a,&b,&all_error,&max_itr);
bisection(&x,a,b,&itr);
do
{
if(fun(a)*fun(x)<0)
b=x;
else
a=x;
bisection(&x1,a,b,&itr);
if(fabs(x1-x)<all_error)
{
printf("after %d iterations, root %6.4f\n",itr,x1);
return 1;
}
x=x1;
}
while(itr<max_itr);
printf("the solution does not converge or iteration are not sufficient");
return 1;
}
