#include<iostream>
#include<algorithm>
#define inf 0x3fffffff
using namespace std;
bool visit[510];
int dis[510],e[510][510],weight[510],w[510],num[510]; //num--统计最短路数量（不唯一）
int n,m,s,d;
void dijkstra(int s){
	num[s]=1;
	dis[s]=0;	
	w[s]=weight[s];
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(!visit[j]&&dis[j]<min){
				u=j; min=dis[j];	
			}
		}
	if(u==-1)
	break;
	visit[u]=true;  //起始点visit怎么办？
	for(int v=0;v<n;v++){  //核心没有问题
		if(e[u][v]!=inf && visit[v]==false){  //处理的是邻接&&未访问的点的边的情况
		if(e[u][v]+dis[u]<dis[v]){
			dis[v]=e[u][v]+dis[u];
			w[v]=w[u]+weight[v];
			num[v]=num[u];
			//num需要处理吗？
		}
		else if(dis[u]+e[u][v] == dis[v]){
			num[v]+=num[u];
			if(w[v]<w[u]+weight[v])
			w[v]=w[u]+weight[v]; //小了才更新
		}
	}
}
}
}
int main()
{
	fill(dis,dis+510,inf);
	fill(e[0],e[0]+510,inf);
	fill(visit,visit+510,false);
	cin>>n>>m>>s>>d;
	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		weight[i]=temp;}
	for(int i=0;i<m;i++){
		int a,b,l;
		cin>>a>>b>>l;
		e[a][b]=e[b][a]=l;
	}
	dijkstra(s);
	cout<<num[d]<< " "<<w[d];
	return 0;
}

/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/