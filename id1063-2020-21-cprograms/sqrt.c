#include <stdio.h>
#include <math.h>
#include <limits.h>

double foo(double num)
{
    double d=num;
    double e=0.0;
    double c=(d+e)/2;
    while(fabs(c*c-num)>0.0001)
    {
	if(c*c > num) {d=c;____________}
        else {e=c;_________}
    }
  return c;
}

int main()
{
   double num;
   scanf("%lf",&num);
   printf("%lf\n",foo(num));
   return 0;
}
