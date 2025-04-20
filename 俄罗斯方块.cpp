/*
	补传半成品版本，相对应的部分位操作系统可以使用
*/


#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//#include <conio.h>
#include <unistd.h>
#define f " "              
#define g"◆"
#define o "@"
#define H  63
void prin(int line,int collumn,char ** pTu);
int main(void)
{
	/*先用二维数组定义了一个基本游戏地图*/
	char *Tu[][H]={{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,"。",f,"下",f,"一",f,"个",f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,"。",f,f,f,"当",f,"前",f,"分",f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,"-","9","9","9","9",f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,"。",f,f,"最",f,f,"高",f,f,"分",f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f," ",f,f,f,f,"0",f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,"。","成","就","：",f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,"。",f,f,"越",f,"打",f,"越",f,"废",f,f,"",f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,"。",f,f,"终",f,"结",f,"游",f,"戏",f,f,"",f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,"。",f,f,f,f,"＊",f,"杰",f,"＊",f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,"。",f,f,f,f,"＊",f,"哥",f,"＊",f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,"。",f,f,f,f,"＊",f,"创",f,"＊",f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,"。",f,f,f,f,"＊",f,"造",f,"＊",f,f,f,f,g},\
               	{g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g},\
				  };
	
    srand(time(NULL));
    int sel = rand() % 5 + 1;
    //printf("随机数%d\n",sel);
    
    int a[2],b[2],c[2],d[2];
    switch(sel)
    {
    case 1:           //横条
    a[0]=0; a[1]=16;
    b[0]=0; b[1]=17;
    c[0]=0; c[1]=18;  
    d[0]=0; d[1]=19;
    break;
    
    case 2:           //竖条
    a[0]=0; a[1]=17;
    b[0]=1; b[1]=17;
    c[0]=2; c[1]=17;  
    d[0]=3; d[1]=17;
    break;
    
    case 3:           //方块
    a[0]=0; a[1]=16;
    b[0]=0; b[1]=17;
    c[0]=1; c[1]=16;  
    d[0]=1; d[1]=17;
    break;
    
    case 4:           //山
    a[0]=0; a[1]=17;
    b[0]=1; b[1]=16;
    c[0]=1; c[1]=17;  
    d[0]=1; d[1]=18;
    
    case 5:           //L
    a[0]=0; a[1]=17;
    b[0]=1; b[1]=17;
    c[0]=1; c[1]=18;  
    d[0]=1; d[1]=19;
    break;
    }
    
    int *p[4]={a,b,c,d};
    for (int i=0;i<4;i++)
    {
    	int x,y;
    	x=p[i][0];
    	y=p[i][1];
    	Tu[x][y]=o;
    }
    
    
    
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t     开始游戏\n");
	prin(sizeof(Tu)/sizeof( * Tu),sizeof(* Tu)/sizeof( ** Tu), * Tu );
	return 0;
}

void prin(int line,int collumn,char ** pTu)
{
	sleep(1);        
	system("clear");          //注意:前面的输入必修以换行结尾，否则出错
	printf("\t\t     杰哥方块1.0\n");
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
    int r=0;
    char *wei[]={g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,g,o,
                 g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g};               

	while(r<95)           //打印结尾
     {
         printf("%s",wei[r]);
         r++;          
     }
}
