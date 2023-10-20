#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a;
	int c;
	char *b[]={"闰年","平年"};
	for (a=2000;a<=2500;a++)
	{
		if (a%4==0&a%100!=0||a%400==0)
		{
		  c=0;
		}
		else
		{
		  c=1;
		}
	printf("第%d年是%s\t ",a,b[c]);
	if (a%4==0)
	   {
		  printf("\n");
   	}
	}
	return 0;
}