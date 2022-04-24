#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=110;
struct Point{
	int x,y,z;
};
int L,R,C;
Point q[N*N*N];
char g[N][N][N];
int dist[N][N][N];
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int bfs(Point start,Point end){
	//最短时间内走出
	q[0]=start;
	memset(dist,-1,sizeof dist);
	dist[start.x][start.y][start.z]=0;
	//queue<Point> q; //可以规规矩矩用队列
	//q.push(start);
	int hh=0,tt=0; //也可以考虑简单模拟一下；
	while(hh<=tt){
		auto t=q[hh++];
		for(int i=0;i<6;i++){
			int x=t.x+dx[i],y=t.y+dy[i],z=t.z+dz[i];
			if(x<0||x>=L||y<0||y>=R||z<0||z>=C||g[x][y][z]=='#') continue;
			if(dist[x][y][z]!=-1) continue;
			dist[x][y][z]=dist[t.x][t.y][t.z]+1;
			if(x==end.x&&y==end.y&&z==end.z) return dist[x][y][z];
			q[++tt]={x,y,z};
		}
	}
	return -1;
}
int main(){
	while(scanf("%d%d%d",&L,&R,&C),L||R||C){
		Point start,end;
		for(int i=0;i<L;i++){ //地牢层数
			for(int j=0;j<R;j++){ //行数
				scanf("%s",g[i][j]);
				for(int k=0;k<C;k++){ //列数
					char c=g[i][j][k];
					if(c=='S') start={i,j,k};
					else if(c=='E') end={i,j,k};
				}
			}
		}
	int distance =bfs(start,end);
	if(distance==-1) cout<<"Trapped!";
	else
	printf("Escaped in %d minute(s).\n",distance);
	}
	return 0;
}