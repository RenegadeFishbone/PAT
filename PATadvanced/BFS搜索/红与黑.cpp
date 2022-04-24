#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N=30;
char g[N][N];
int n,m;
int BFS(PII start){
	queue<PII> q;
	q.push(start);
	g[start.x][start.y]='#';
	int res=0;
	int dx[]={-1,0,1,0};
	int dy[]={0,1,0,-1};
	while(q.size()){
		auto t=q.front();
		q.pop();
		res++;
		for(int i=0;i<4;i++){
			int sx=dx[i]+t.x,sy=dy[i]+t.y;
			if(sx<0||sy<0||sx>=m||sy>=n||g[sx][sy]!='.')
			continue;
			g[sx][sy]='#';
			q.push({sx,sy});
		}
	}
	return res;
}
int main(){
	PII start;
	while(cin>>n>>m,n||m){
		for(int i=0;i<m;i++) scanf("%s",g[i]);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(g[i][j]=='@')
				start={i,j};
			}
		}
		cout<<BFS(start)<<endl;
	}
	return 0;
}

