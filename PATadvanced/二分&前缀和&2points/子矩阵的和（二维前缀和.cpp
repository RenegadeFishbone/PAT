#include<iostream>
#include<cstdio>
using namespace std;
const int N=10010;
int a[N][N],s[N][N];
int main(){
	int n,m,num;
	cin>>n>>m>>num;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
		cin>>a[i][j];
		s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	}
	while(num--){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]<<endl;
	}
	return 0;
}