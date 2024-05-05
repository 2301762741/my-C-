#include<stdio.h>
#include<stdlib.h>
#define ci 5                 //循环的次数
#define XH c=0;c<ci;c++     //进行循环的写法
int c;
     /*问:为啥数组数不对时会跳127?*/
int main(void)
{
	int a=0;            //a记录最大值
	int b[ci];          //运用宏定义保证
	for(XH)                 //数组的数目正确!/
	{
  	printf("请输入一个数!\n");
  	scanf("%d",&b[c]);
  	
  	if(b[c]>a)
  	  a=b[c];
  	system("clear");
    }
    printf("录入完成，它的结果是:\n");
    for(XH)
    {       
   	printf("%d号数的值是%d\t\n",c+1,b[c]);
    }
	printf("\n其中它们的最大值是%d",a);
	return 0;
}