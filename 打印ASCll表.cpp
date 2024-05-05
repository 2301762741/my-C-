#include<stdio.h>
#include<stdlib.h>
#define su 10e2              //定义终点位置

int main(void)
{
	for(int b=33;b<=su;b++) //定义起点位置
	{
	printf("%d的ASCll表为%c\t",b,b);
		if(b%4==0)
		{
       	printf("\n");
		}	
	}
	return 0;
}
