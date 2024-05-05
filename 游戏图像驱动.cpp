#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#define f " "              
#define g "■"
#define h "@"
#define H  27
void prin(int line,int collumn,char ** pTu);
//演示代码
int main(void)
{
	/*先用二维数组定义了一个基本游戏地图*/
	char *Tu[][H]={ {g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g},\
					{g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g},\
					{g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g},\
					{g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g},\
					{g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g},\
					{g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g},\
					{g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g},\
					{g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g},\
					{g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g},\
					{g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g},\
				  };
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t     开始游戏\n");
	prin(sizeof(Tu)/sizeof( * Tu),sizeof(* Tu)/sizeof( ** Tu), * Tu );
	Tu[0][10]=h;
	prin(sizeof(Tu)/sizeof( * Tu),sizeof(* Tu)/sizeof( ** Tu), * Tu );
    Tu[0][10]=f;
	Tu[1][10]=h;
	prin(sizeof(Tu)/sizeof( * Tu),sizeof(* Tu)/sizeof( ** Tu), * Tu );
    Tu[1][10]=f;
	Tu[2][10]=h;
	prin(sizeof(Tu)/sizeof( * Tu),sizeof(* Tu)/sizeof( ** Tu), * Tu );
	return 0;
}

//主要实现函数
void prin(int line,int collumn,char ** pTu)
{
	sleep(1);
	system("clear");          //注意:前面的输入必修以换行结尾，否则出错
	int	i=0,j=0;
	while(i < line)           //打印地图的大循环
	{
       printf("%s",  * pTu++);
       j++;
	   if( j == collumn)
		{
			j = 0;
			i++;
			printf("\n");
		}
    }
}