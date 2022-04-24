#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=1010;
bool g[N][N];  //邻接矩阵存储
bool vis[N];
int n,th,num,ans;
int bfs(int start){
	int cnt=-1;
	int l=0;
	memset(vis,false,sizeof vis);	
	queue<int> q;
	q.push(start);
	while(q.size()&&l<=th){  	//搜索不得超过th层--层序遍历
		int t=q.size();
		for(int i=0;i<t;i++){
		auto tmp=q.front();
		cnt++;
		for(int i=1;i<=n;i++){
			if(i==start) continue;
			if(!vis[i]&&g[i][tmp]){
				vis[i]=true;
				q.push(i);
			}
		}
		q.pop();
	}
		l++;  //层数统计
	}
	return cnt;
}
int main(){
	cin>>n>>th;
	for(int i=1;i<=n;i++){
		int tmp,b;
		cin>>tmp;
		for(int j=0;j<tmp;j++) 
		{
			cin>>b;
			g[i][b]=true;
		}
	}
	cin>>num;
	while(num--){
		int tmp;
		cin>>tmp;
		cout<<bfs(tmp)<<endl;  
	}
	return 0;
}