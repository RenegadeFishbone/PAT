#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=100;
struct point{
	int x,y,z;
};
//int g[1300][1300][70];
//bool visit[1300][1300][70];
int g[70][1300][1300];
bool visit[70][1300][1300];
point q[N*N*N];  //队列
int m,n,l,t,ans;
int dx[]={1,-1,0,0,0,0};  //次序不重要，六个方向都走一遍就可以
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int bfs(point start){
//	int tt=0,hh=0,cnt=0;
//	memset(q,0,sizeof q);
//	q[0]=start;
//	visit[start.x][start.y][start.z]=true;
//	while(hh<=tt){
//		auto tmp=q[hh++];
//		cnt++;
//		for(int i=0;i<6;i++){
//			int tx=tmp.x+dx[i],ty=tmp.y+dy[i],tz=tmp.z+dy[i];
//			if(tx<0||tx>=m||ty<0||ty>=n||tz<0||tz>=l||visit[tx][ty][tz]||g[tx][ty][tz]==0)  //三维坐标怎么说
//			continue;
//			visit[tx][ty][tz]=true;
//			q[++tt]={tx,ty,tz};
//		}
//	}
///////////
	int cnt=0;
	queue<point> q;
	q.push(start);
	visit[start.x][start.y][start.z]=true;
	while(!q.empty()){
		auto tmp=q.front();
		q.pop();
		cnt++;
		for(int i=0;i<6;i++){
			int tx=tmp.x+dx[i],ty=tmp.y+dy[i],tz=tmp.z+dz[i];
			if(tx<0||tx>=l||ty<0||ty>=m||tz<0||tz>=n||g[tx][ty][tz]==0||visit[tx][ty][tz])
			continue;
			else{
				visit[tx][ty][tz]=true;
				q.push({tx,ty,tz});
			}
		}
	}
	if(cnt>=t) return cnt;
	else
	return 0;
}
int main(){
	cin>>m>>n>>l>>t;
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				scanf("%d",&g[i][j][k]);
			}
		}
	}
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				if(g[i][j][k]==1&&!visit[i][j][k])
					ans+=bfs({i,j,k});
			}
		}
	}
	cout<<ans;
	return 0;
}