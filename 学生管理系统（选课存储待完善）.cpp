
/****************************************************************
  学生管理系统纯手打版，累死~还不太会数据库！
 ****************************************************************/

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

const string Filename = "STUD.txt";    //本地储存文件保存路劲

class MyException : public exception {
public:
	MyException(string err){
		this->err=err;	
	}
	string what(){
		return err;//"自定义异常：发生错误!";
	}
private:
	string err;
};

class cource{
public:
	string CName;
	string CPlace;
	string CTime;
	
	cource() {}
	cource(string name,string place,string time)
	{
		CName=name; 
		CPlace=place; 
		CTime=time;
	}
	void display() {cout<<"   "<<CName<<" - "<<CPlace<<" - "<<CTime<<endl;}
};

class student{
public:
	long long Num;
	string Name;
	int Class;
	set<string> Course;

	student() {}
	student(long long num,string name,int clas)//,set<int> course)
	{
		Num=num;
		Name=name;
		Class=clas;
	}
	void display() {cout<<Num<<" "<<Name<<" "<<Class<<" "<<endl;}
	
protected:
	
private:
	
};

void encryptFile(void);  //保存文件
void decryptFile(void);     //读取文件
void addStud(void);  //添加学生
void subStud(void);  //删除学生
void addCour(void);  //学生选课
void catCour(void);  //查询课程 
vector<student> STUDENT;
unordered_map<string,cource> COUESE;
map<string,bool> courHash;//课程检查
map<string,bool> numHash; //学号检查
int Nclas=10;  //最大班级人数

int main()
{
	decryptFile();

//	vector<string> COUR{"高数","数据结构","C++","嵌入式"};
//	courHash.insert(COUR.begin(),COUR.end());
	//设置已有课程
	COUESE["高数"]=cource ("高数","二教","8:30-10:05");  		courHash["高数"]=true;
	COUESE["数据结构"]=cource ("数据结构","四教","10:20-11:55");  	courHash["数据结构"]=true;
	COUESE["C++"]=cource ("C++","一教","14:30-16:05");			courHash["C++"]=true;
	COUESE["嵌入式"]=cource ("嵌入式","二教","16:20-10:20"); 		courHash["嵌入式"]=true;
	
	while (1)
	{
		try{
			
			char select;
			cout<<"***********功能选择****************\n"
			"   1.添加学生      4.学生选课  \n"
			"   2.删除学生      5.查询学生选(存待)     \n"	
			"   3.查询学生信息  6.退出\n"
			"***********************************\n";
			cin>>select;
			
			switch(select)
			{
			case '1':
				addStud();             //添加学生
				break;
				
			case '2':
				subStud();			  //删除学生
				break;
				
			case '3':
				for(auto a:STUDENT)   //查看学生
					a.display();
				break;
				
			case '4':
				addCour();          		  //学生选课
				break;
				
			case '5':
				catCour();           //查询学生选课
				break;
				
			case '6':
				goto End;   //跳出结束
				break;
				
			default:
				throw MyException("参数错误，请重新输入!");
				break;	
			}
		}
		catch(MyException& e){
			cerr << "异常:" << e.what() << endl;
		}
	}	
	End:
	encryptFile();
	return 0;
}

long long to_longl(string tmp)
{
	long long ans=0,k=1;
	for(int i=tmp.length()-1;i>=0;i--){
		ans+=(tmp[i]-'0')*k;
		k*=10;
	}
	return ans;
}

void addStud(void)
{
	string num,name,clas;
	cout<<"请以:“学号 姓名 班级”的格式输入"<<endl;
	cin>>num>>name>>clas;
	
	if(!num.length() || numHash[num]==true) 
		throw MyException("学号错误");
	if(!name.length()) 
		throw MyException("姓名错误");
	if(!clas.length())
		throw MyException("班级错误");
	
	numHash[num]=true;
	student stu{to_longl(num),name,(int)to_longl(clas)};
	STUDENT.emplace_back(stu);
	cout<<"添加成功！"<<endl;
}

void subStud(void)
{
	string num;
	cout<<"请输入删除学生的学号:"<<endl;
	cin>>num;
	
	if(!num.size() || numHash[num]==false) 
		throw MyException("学号错误");
	
	for(int i=0;i<STUDENT.size();i++)
		if(STUDENT[i].Num==to_longl(num)){
			STUDENT.erase(STUDENT.begin()+i);
			numHash[num]=false;
			cout<<"删除成功！"<<endl;
		}
}

void addCour()
{
	string num;
	cout<<"请输入选课学生的学号:"<<endl;
	cin>>num;
	
	if(!num.length() || numHash[num]==false) 
		throw MyException("学号错误");
	
	cout<<"请选择以下课程："<<endl;
	for(auto [_,y]:COUESE)
		y.display();
	
	for(int i=0;i<STUDENT.size();i++)
		if(STUDENT[i].Num==to_longl(num)){
			string s; cin>>s;
			if(courHash[s])
				STUDENT[i].Course.emplace(s),
				cout<<"选课成功"<<endl;
			else
				throw MyException("选课错误");
		}
}

void catCour()
{
	string num;
	cout<<"请输入查询学生的学号:"<<endl;
	cin>>num;
	
	if(!num.length() || numHash[num]==false) 
		throw MyException("学号错误");
	
	for(int i=0;i<STUDENT.size();i++)
		if(STUDENT[i].Num==to_longl(num)){
			for(auto a:STUDENT[i].Course)
				COUESE[a].display();
		}
}


void encryptFile() {
	ofstream encFile(Filename, ios::binary);
	
	if (!encFile.is_open()) {
		throw MyException("The file could not be opened.");
		return;
	}
	
	//保存文件
	string encoded,course;
	
	for(auto a:STUDENT)   //查看学生
	{
		for(string b:a.Course)
			course+=(","+b);
		encoded+=(to_string(a.Num)+' '+a.Name+' '+to_string(a.Class)+' '+course.substr(1,course.length()-1)+'\n');
	}
	
	// 写入新文件
	encFile << encoded;
	
	// 关闭文件
	encFile.close();
}

void decryptFile() {
	vector<string> zu(3);
	ifstream encFile(Filename, ios::binary);
	
	if (!encFile.is_open()) {
		throw MyException("The file could not be opened.");
		return;
	}
	
	// 读取文件内容
//	string s;
//	while(getline(encFile,s)){
//		cout<<s;
//	}
	
	string encoded((istreambuf_iterator<char>(encFile)), {});
	//string encoded = jiAmi(buffer);
	
	//解析文件
	string tmp,s; student Tstu;int k=1;
	for(int i=0;i<encoded.size();i++)
	{
		if(encoded[i]==' ' || encoded[i]=='\n'){
			switch (k) {
			case 1:
				//int num=to_longl(tmp);
				Tstu.Num=to_longl(tmp);
				numHash[tmp]=true;
				tmp.clear();
				k++;
				break;
			case 2:
				Tstu.Name=tmp; 
				tmp.clear(); 
				k++;
				break;
			case 3:
				Tstu.Class=to_longl(tmp);
				tmp.clear();
				k++;
				break;
			default:
				for(auto a:tmp)
					if(a=='\n'){
						if(s.length()){
							Tstu.Course.emplace(s);	
						}
						break;
					}
					else if(a==','){
						Tstu.Course.emplace(s);
					}
					else{
						s+=a;
					}
				STUDENT.emplace_back(Tstu);
				tmp.clear();
				s.clear();
				k=1;
				break;
			}
		}
		else
			tmp+=encoded[i];
	}
	
	// 关闭文件
	encFile.close();
}
