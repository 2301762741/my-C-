#include<stdio.h>
int main()
{
	int n,max;   char z[10];
	max=0;  z[10]={0};
	scanf("%d",&n);
	while(n>0)
	{
	   int S=0;  
	   char s[10]={0};
	   scanf("%s",s);
	   int size=sizeof (s)/sizeof (s[0]);
   	for(int i=0;i<size;i++)
   	{
   		S+=s[i];
	   }
   	if(S>max)
   	{
           max=S;
          // z=s;
           for(int i=0;i<size;i++)
           {
           	z[i]=s[i];
           }
       }
	   n--;
	}
//	printf("%s",z);
    int size=sizeof (z)/sizeof (z[0]);
	for(int i=0;i<size;i++)
	{
    	printf("%c",z[i]);
    }
    printf("最大为%d",max);
    return 0;
}