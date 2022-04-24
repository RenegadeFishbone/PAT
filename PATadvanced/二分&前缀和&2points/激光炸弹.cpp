#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=5e3+10;
int s[N][N];
int n,r;
int main(){
	cin>>n>>r;
	r=min(r,5001);  //题目数据--有可能爆掉
	for(int i=0;i<n;i++){
		int x,y,num;
		scanf("%d%d%d",&x,&y,&num);
		s[++x][++y]+=num;
	}
	for(int i=1;i<=5001;i++){
		for(int j=1;j<=5001;j++){
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];//+=把自身加上了
		}
	}
	int ans=0;
	for(int i=r;i<=5001;i++){
		for(int j=r;j<=5001;j++){
			ans=max(ans,s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r]);
		}
	}
	cout<<ans;
	return 0;
}