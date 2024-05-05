#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	long int a;
	a=10000;
	for(long int b=1;;b++)
	{
	   if(b*b==a)
	    printf("√%d的值等于%d\n",a,b);
    }
	return 0;
}