/*
                   时间函数的用法
time_t time(time_t *t);：返回当前距1970年1月1号的秒 参数：一般填充NULL
struct tm *localtime(const time_t *timep);//将秒数转换为本地详细时间描述
 char *ctime(const time_t *timep);//将秒数转换为本地时间字符串
 struct tm *gmtime(const time_t *timep);//将秒数转换为国际标准时间详细描述
 char *asctime(const struct tm *tm);//将时间的详细描述转换为字符串

struct tm {
                  int tm_sec;         / 秒:取值区间为[0,59]  /
                  int tm_min;         /分:取值区间为[0,59]/
                  int tm_hour;        / 时:取值区间为[0,23] /
                  int tm_mday;        / 一个月中的日期:取值区间为[1,31]/
                  int tm_mon;         / 月份(从一月开始， 0 代表一月) :取值区间为[0,11] /
                  int tm_year;        / 年份:其值等于实际年份加上 1900 /
                  int tm_wday;        /  星期:取值区间为[0,6],其中 0 代表星期天,1 代表星期一,以此类推 
                  int tm_yday;        /从每年的 1 月 1 日开始的天数:取值区间为[0,365],其中            0 代表 1 月 1 日,1 代表 1 月 2 日，以此类推
                  int tm_isdst;       / 夏令时 /
              };

time_t tm;//定义一个接收秒数的 (结构变量)
注意:此获取的秒数是从1900年一月一日计算的

time(&tm);//把接受的值给tm变量
或者tm=time(NULL);

ctime(&tm);//时间处理函数，能将秒数转换为本地时间的'字符串'
localtime(&tm);//将秒数转化为本地时间的描述，可以用时间的struct结构单独转化
getime(&tm);//转国际标准时间，带/*年/月/日/小时/分/星期/

*/

#include<stdio.h> 
#include<time.h> 
int time1()
{
 char *day;
 time_t tm = 0;
 time(&tm);//获取秒
 day = ctime(&tm);//将秒转换为本地时间字符串，注意传参是地址传递
 //printf("%s", ctime(&tm));
 printf("%s", day);//打印本地时间。会自动换行
 return 0;
}

int time2()
{
 struct tm *day;//定义一个接收本地详细时间的结构体变量，在上面有这个结构的详细说明
 time_t tm = 0;
 time(&tm);
 day = localtime(&tm);//将秒数转换为本地详细时间描述
 printf("%d year %d month %d day %d hour %d min %d sec\n",1900+day->tm_year,1+day->tm_mon,day->tm_mday,day->tm_hour,day->tm_min,day->tm_sec);//将时间通过访问结构体成员变量的方法逐个输出，注意年份是从1900年开始，要+1900，月份也要加1
 return 0;
}

/*年/月/日/小时/分/星期/*/
int time3()
{
 struct tm *day;
 char *day1;
 time_t tm = 0;
 time(&tm);
 day = gmtime(&tm);//将秒数转换为国际标准**时间详细描述**
 printf("%d year %d month %d day %d hour %d min %d sec\n",1900+day->tm_year,1+day->tm_mon,day->tm_mday,day->tm_hour,day->tm_min,day->tm_sec);
 day1 = asctime(day);//将**时间的详细描述**转换为字符串
 printf("%s",day1);//输出字符串
 //printf("%s",asctime(day));
 return 0;
}

int main()
{
	printf("%d",time2);
}