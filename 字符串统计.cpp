#include <bits/stdc++.h> 
using namespace std;
int N=3;  //定义执行次数
char c='$';  //定义输出的自定义字符串

int main()
{
	map<char,int> ha;  //哈希表记录出现字符
	
	while(N--){
		string s;
		cin>>s;
		for(char a:s)  //遍历字符
			ha[a]++;
	}
	
	for(auto [x,y]:ha)
	{{
		cout<<x<<" ";  //输出出现字符
		while(y--){    //输出对应字符个数
			cout<<c;
		}
		cout<<endl;
	}}
	
	return 0;
}
