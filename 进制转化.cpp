#include<stdio.h>
#define max f-1
    /*注意:此数学算法范围受到到位数b与类型的限制!*/
int main()
{
	int a,b,c,d,e,f;       //b为位数，d为计算结果
        a=500;             //初始要计算的数
		c=1;               //进制算法幂乘的初始化
		f=2;               //f为进制数
		b=7;               //设置位数
	printf("十进制数%d的 %d位 %d进制 为\n",a,b+1,f);

	for (b=7;b>=0;b--)     //位数运算
	{
		for (e=b;e>0;e--)  //幂运算
		{
			c=c*f;
		}
	if (e==b&&a<c*max)
	  {
	     printf("(兄弟，你的数有点大，请修改位数!)");
	     break;
  	}
	else
	  {
  	d=a/c;                 //计算单次结果
  	a=a%c;                 //除余算法
  	printf("%d",d);
  	c=1;
	  }
	}
	return 0;
}