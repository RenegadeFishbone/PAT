#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#define x first
#define y second
using namespace std;
const int N=210;
int n,m;
char g[N][N];
int dist[N][N]; //记录时间
typedef pair<int,int> PII;
int bfs(PII start,PII end){
	queue<PII> q;
	memset(dist,-1,sizeof dist);//重置
	dist[start.x][start.y]=0;//起点从0开始计算
	q.push(start);
	int dx[4]={-1,0,1,0};
	int dy[4]={0,1,0,-1};
	while(q.size()){
		PII t=q.front();
		q.pop();
		if(t==end) return dist[t.x][t.y];  //找到出口了
		for(int i=0;i<4;i++){
			int x=t.x+dx[i],y=t.y+dy[i];
			if(x<0||x>=n||y<0||y>=m) continue; //出界了
			if(g[x][y]=='#') continue;//是墙
			if(dist[x][y]!=-1) continue; //不是第一次走--不会兜圈子浪费时间
			dist[x][y]=dist[t.x][t.y]+1;
			q.push({x,y});
		}
	}
	return -1;
	//看吧
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%s",g[i]);//技巧
		PII start,end;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(g[i][j]=='S'){
					start={i,j}; //找到起点
				}
				else if(g[i][j]=='E')
					end={i,j};
			}
		}
		int distance =bfs(start,end);
		if(distance ==-1) puts("oop!");
		else cout<<distance<<endl;
	}
		return 0;
}
