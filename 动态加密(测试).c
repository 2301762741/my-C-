#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>      //错误代码
#define changeMAX

      
int twoch(int num)      //二进制转换函数
{
	unsigned mask;
	mask=1u<<31;//定义一个最大位数的二进制数，首位为1，其余为0
	for(;mask;mask>>=1)//每次1右移一位，直到mask为0
	{
		printf("%d",num&mask?1:0);//按位与运算，逐一输出num二进制数的每一位
	}
	return 0;
}


int A_change()          //动态加密算法
{
    srand(time(NULL));  //随机数的写法
	int H=rand()%9+1;
	return H;
}

void addmi(char *p)     //此处是加密核心逻辑，修改此处可提高加密复杂度
{
	//assert(p != NULL);  //防止空指针出现
	int H=A_change();  int i=0;
	*p<<=1;                        //////待实验测试
	//printf("\t其密文为:%d",H);
    while (*p != '\0')
    {
    	*p+=H+++i;
    	i+=++H+i;
    	
    /*	if (*p>57&*p<62)
    	   *p-=10;
    	                          //循环排列
    	if ((*p>90&*p<95)|*p>122)
    	   *p-=25;
    	    	       */
    	twoch(*p++);
    }
    printf("\n\n");
}

void A_prin(char* p)
{
	assert(p);
    printf("\nPlease wirte down 眀文:");
    scanf("%s",p);
    printf("\n");
}

void jiAmi(char *p)
{
	assert(p!=NULL);
	
	A_prin(p);  //获取输入

    A_change();   //变化算法
    
    addmi(p);   //加密算法
}

/*******上面是加密算法部分*******/

int delmi(char *p , const int* H)
{	//printf("\n眀文为: %d\n",&H);
	    while (*++p != '\0')
    {
    	*p-=*H;
    	
    /*	if (*p>67&*p<72)
    	   *p+=10;
    	
    	if ((*p>100&*p<105)|*p>122)
    	   *p+=25;
    	    	   */
    	printf("%c",*p);
    }
    printf("\n\n");
}

int E_change(char *p,int * const H)
{
	assert(p);
    *H=int(*p)-48;
    
	//E=sizeof (mi)/sizeof (mi[0]); 

	//H=(int)mi[0];                /////////////
    return *H;
}

void E_prin(char *p)
{
	assert(p);	
    int E,H=0;  //E为变化参数的长度，H为变化参数的大小
	printf("Please wirte down 密文:");
    scanf("%s",p);
    printf("\t其明文为:");   
}

void jiEmi(char *p)
{
	int H;
	
	assert(p!=NULL);
	
	E_prin(p);  //获取眀文
	
	H=E_change(p,&H);//动态加密解密
	
    delmi(p,&H);
	

}
	
char start()
{
	char select;
	printf("***********功能选择************\n"
	       "        1.加密\n"
	       "        2.解密\n"
	       "        3.退出\n"
	       "*******************************");
	       scanf("%s",&select);
	       return select;
}



int main()
{
    char a[100]={0};
    while (1)
    {
    	char n=start();    //初始化菜单
    	switch(n)
    	{
    		case '1':
    		   jiAmi(a);   //初级加密算法(测试)
    		   break;
    		
    		case '2':
    		   jiEmi(a);   //解密算法
    		   break;
    		
    		case '3':
    		   goto End;   //跳出结束
    		   break;
    		   
    		default:
    		   printf("\n参数错误，请重新输入!\n\n\n");
    		   break;
    		
    	}
    }
    
End:
    return 0;
}
