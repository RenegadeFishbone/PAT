#include<iostream>
#include<cstdio>
using namespace std;
const int N=10010;
int main(){
	int n;
	cin>>n;
	int cnt=n;
	while(n>=3){
		cnt+=n/3;
		n=n/3+n%3;
	}
	cout<<cnt;
	return 0;
}