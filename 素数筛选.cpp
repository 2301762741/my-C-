#include<iostream>
#include<vector>
using namespace std;

bool isSu(long n)
{
    for(int i=2;i<n/i+1;i++)    //n /n  i2<n -> i<n/i
       if(n%i==0) return 0;
    
    return 1;
}

void Sai1(long n)
{
 while(n--)
   if(isSu(n)&n>2) //2理论上是素数 
      cout<<n<<endl;
}

void Sai2(long n)  //埃式筛
{
  int count=0;
    vector<int> ha(n,1); 
	
    for(int i=2;i<=n/i;i++)
        if(ha[i]) 
            for(int j=i*i;j<n;j+=i)
                ha[j]=0;

    for(int i=3;i<n;i++)  //2理论上是素数 
        if(ha[i])  cout<<i<<endl;
 
}
 
 void Sai3(long n)  //欧拉线性筛
{

 
}
 
int main()
{
 
 long shu=1e2;
 int a,b; a=0;b=0;
 
 //Sai1(shu);
 
 Sai2(shu);
 
 //Sai3(shu);
 
 //cout << isSu(13) <<endl;
 
 return 0;
}
