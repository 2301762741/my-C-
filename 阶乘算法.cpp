#include<stdio.h>
#include<stdlib.h>
#define n 100        //n的阶乘
double age(int a);

int main(void)
{
	printf("1+2+3……+%d的结果是:%f",n,age(n));
	return 0;
}

double age(int a)
{
	if(a<0)
	   printf("输入错误");
	else if(a==1)
    	   return 1;
    	else /*if(a%2==0)*/
	       return age(a-1.0)+a;
    /*else        (有减算法)
       return age(a-1)+a;*/

}