#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n,num;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		num=stoi(s);
		int len=s.length();
//		cout<<s<<endl;
		int a=stoi(s.substr(0,len/2));
		int b=stoi(s.substr(len/2));
		if(a*b!=0&&num%(a*b)==0)  //浮点错误--可能除了0
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}