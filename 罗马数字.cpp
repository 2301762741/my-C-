#include <bits/stdc++.h> 
using namespace std;

unordered_map<char, int> romanMap = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};

int main()
{
	string romanNum;
	cin>>romanNum;
	
	int Num=0,prev=0;
	
	for (int i = romanNum.size() - 1; i >= 0; i--) {
		int curr = romanMap[romanNum[i]];
		
		if (curr < prev) {
			Num -= curr;
		} else {
			Num += curr;
		}
		
		prev = curr;
	}
	
	cout<<Num;
	return 0;
}
