//输出一个数的二进制
#include<stdio.h>
#define twoMAX 16
int main()
{
	int num;
	unsigned mask;
	scanf("%d",&num);
	mask=1u<<twoMAX-1;//定义一个最大位数的二进制数，首位为1，其余为0
	for(;mask;mask>>=1)//每次1右移一位，直到mask为0
	{
		printf("%d",num&mask?1:0);//按位与运算，逐一输出num二进制数的每一位
	}
	printf("\n");
	return 0;
}
