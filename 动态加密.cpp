#include <bits/stdc++.h> 
using namespace std;

int start();						
string jiAmi();
string jiEmi();
string E_change(string MI,int H);

int main()
{
	while(1)
	{
		int select=start();  //初始化菜单
			
		switch(select)
		{
			case 1:
				jiAmi();   //初级加密算法(测试)
				break;
				
			case 2:
				jiEmi();   //解密算法
				break;
					
			case 3:
				goto End;   //跳出结束
				break;
					
			default:
				cout<<"\n参数错误，请重新输入!\n\n\n";
				break;
		}
	}
	
End:
	cout<<"Thanks for using!";
	return 0;
}

int start()
{
	int select;
	cout<<("***********功能选择************\n"
			"        1.加密\n"
			"        2.解密\n"
			"        3.退出\n"
			"*******************************\n");
	cin>>select;
	return select;
}

string jiAmi()
{
	string MI,RM;  //获取眀文
	cin>>MI;
	RM=MI;
	
	srand(time(NULL));  //随机数的写法
	int H=rand()%99+10;	//动态加密解密
	
	string cH=to_string((H));
	MI=E_change(MI,H);  //加密算法
	
	cout<<cH[0]+MI+cH[1]<<endl;
	return RM;	
}

string jiEmi()
{
	string MI,RM,HM;  //获取密文
	cin>>MI; RM=MI;
	int Lsize=MI.length()-1;
	
	int H=(MI[0]-'0')*10+MI[Lsize]-'0';
	
	for(int i=1;i<Lsize;i++){
		HM+=MI[i]-H;  //可能为负多而出现异常，注意！
	}
	
	cout<<HM<<endl;
	return RM;	
}


string E_change(string MI,int H)
{
	for(char& a:MI)
		a=(a+H)%CHAR_MAX;  //可自定义模数放超界
	
	return MI;   
}
