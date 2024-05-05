#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define cope 9999          //写下的遍数
#define name "'你的名字'"

int main(void)
{
          /*获取本地时间的的写法*/
 struct tm *day;//定义一个接收本地详细时间的结构体变量，在上面有这个结构的详细说明
 time_t tm = 0;
 time(&tm);
 day = localtime(&tm);//将秒数转换为本地详细时间描述
 printf("%d年 %d月 %d日 %d:%d生成\n",1900+day->tm_year,1+day->tm_mon,day->tm_mday,day->tm_hour,day->tm_min,day->tm_sec);//将时间通过访问结构体成员变量的方法逐个输出，注意年份是从1900年开始，要+1900，月份也要加1

            	/*这个可以写规律性回答*/
	//char * numstr[] = { "个","十","百","千","万","十万","百万","千万","亿","十亿"};
	FILE * fp = fopen("XiaoHan.txt","w");
	if(fp == NULL)
		exit(0);
	fprintf(fp,"现在是%d年 %d月 %d日 %d:%d\n",1900+day->tm_year,1+day->tm_mon,day->tm_mday,day->tm_hour,day->tm_min,day->tm_sec);
	fputs("睡不着ㄟ( ▔, ▔ )ㄏ，于是我一遍遍地写下了你的名字\n"
			//"int main(void)\n"  //继续说
			,fp);
	for(int innumber=0;innumber<cope;innumber++)
	{
        char a[]=name;
		fprintf(fp,"%s，\t第%d遍写你的名字。\n",a,innumber+1);
	}
    fputs("不知不觉中你的名字竟写了满了一页，整整一万遍！\n"
	  	"\t\t我觉得。。。。。\n"
	  	"\n"
	  	"你还是不要出现在面前好了，免得我以后都睡不着😂"
			,fp);
	fclose(fp);
	return 0; 
}