#include<stdio.h>
#include<stdlib.h>
#define f " "              
#define g "■"

int main()
{
	int i,j;
	i=0; j=0;
	printf("\t\t   杰哥方块1.0\n");
	
	while (i<35)
	{
	   printf("■■■");
	   while (j<6)
	   {
	   	printf("\t");
	   	j=j+1;
	   }
	   i=i+1;
	   j=0;
	   printf("■■■\n");
	}
	
	int a,b;
	a=0; b=0;
	while (a<2)
	{
	   while (b<33)
	   {
	       printf("■");
	       b=b+1;
	   }
	   printf("\n");
	   a=a+1;
	   b=0;
	}
	
	return 0;
}