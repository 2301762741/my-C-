
/****************************************************************
  本代码由曾经写人动态加密算法改写，源代码见”动态加密.cpp”
 ****************************************************************/

#include<bits/stdc++.h>
using namespace std;

void decryptFile(const std::string& encFilename);
void encryptFile(const string& srcFilename, const string& encFilename);
string jiAmi(string);  //动态加密
string jiEmi(string);  //动态解密
string E_change(string MI,int H);  //自定义加密算法

int main() {
	const string oriFilename = "original.txt";
	const string encFilename = "encrypted.txt";
	
	// 加密文件
	encryptFile(oriFilename, encFilename);
	
	// 解密文件并打印内容
	decryptFile(encFilename);
	
	getchar();
	return 0;
}

//动态加密
string jiAmi(string MI)
{
	srand(time(NULL));  //随机数的写法
	int H=rand()%30+10;	//动态加密解密
	
	string cH=to_string((H));
	MI=E_change(MI,H);  //加密算法
	
	return cH[0]+MI+cH[1];	
}

//动态解密
string jiEmi(string MI)
{
	string HM;  

	int Lsize=MI.length()-1;
	int H=(MI[0]-'0')*10+MI[Lsize]-'0';
	
	for(int i=1;i<Lsize;i++){
		HM+=MI[i]-H;  //可能为负多而出现异常，注意！
	}
	
	return HM;	
}

//自定义加密算法
string E_change(string MI,int H)
{
	for(char& a:MI)
		a=(a+H)%CHAR_MAX;  //可自定义模数放超界
	
	return MI;   
}

// 将文本文件内容加密并写入新文件
void encryptFile(const string& srcFilename, const string& encFilename) {
	ifstream srcFile(srcFilename, ios::binary);
	ofstream encFile(encFilename, ios::binary);
	
	if (!srcFile.is_open() || !encFile.is_open()) {
		cerr << "One of the files could not be opened." << endl;
		return;
	}
	
	// 读取文件内容
	string buffer(istreambuf_iterator<char>(srcFile), {});
	
	// 进行编码
	string encoded = jiAmi(buffer);
	
	// 写入新文件
	encFile << encoded;
	
	// 关闭文件
	srcFile.close();
	encFile.close();
}

// 将加密的文件内容解密并输出
void decryptFile(const std::string& encFilename) {
	ifstream encFile(encFilename, ios::binary);
	
	if (!encFile.is_open()) {
		cerr << "The file could not be opened." << endl;
		return;
	}
	
	// 读取文件内容
	string encoded((istreambuf_iterator<char>(encFile)), {});
	
	// 进行解码
	string decoded = jiEmi(encoded);
	
	// 输出解密后的内容
	cout << "Decrypted content: " << endl << decoded << endl;
	
	// 关闭文件
	encFile.close();
}
