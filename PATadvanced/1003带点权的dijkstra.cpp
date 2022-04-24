#include<iostream>
#include<algorithm>
#define inf 999999
using namespace std;
int dist[510],num[510],weight[510],w[510]; //dist--最基本的 num--统计最短路数量 weight--点权值 w--结果点权 
int e[510][510];
bool visit[510];
int main()
{
	fill(visit,visit+510,false);
	fill(dist,dist+510,inf);
	fill(e[0],e[0]+510*510,inf);
	int n,m,s,d;
	cin>>n>>m>>s>>d;
	for(int i=0;i<n;i++){
		int tempw; cin>>tempw;
		weight[i]=tempw;
	}
	for(int i=0;i<m;i++){
		int a,b,l;
		cin>>a>>b>>l;
		e[a][b]=l; e[b][a]=l;
	}
	dist[s]=0;//起点
	w[s] = weight[s]; 
	num[s] = 1;
	//dijkstra
	for(int i=0;i<n;i++){
		int u=-1,minn=inf;
		for(int j=0;j<n;j++){
			if(visit[j]==false && dist[j]<minn){
				minn = dist[j];     //找此时dist[]最小值 
				u = j;
			}
		}
		if(u == -1)
		break; //全部已经收录
		visit[u] = true;
		for(int j=0;j<n;j++){
			if(e[u][j] != inf && visit[j] == false){ //邻接&&没有被访问过 
			if(dist[j] > dist[u] + e[u][j]){
				dist[j] = dist[u]+e[u][j];
				num[j] = num[u]; //? 
				w[j] = w[u]+weight[j]; //点权值↑ 
			} 
			else if(dist[j] == dist[u]+e[u][j]){
				num[j] += num[u]; //是加和不是简单++
				if(w[j] < w[u]+weight[j]){
					w[j] = w[u] + weight[j]; //点权最大值 
				} 
			}	
			}
		} 
	}
	cout << num[d] << " " << w[d];
	return 0;
}
