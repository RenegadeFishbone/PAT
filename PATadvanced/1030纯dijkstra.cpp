#include<iostream>
#include<algorithm>
#define inf 0x3fffffff
using namespace std;
int G[510][510];
int dis[510],c[510][510],cost[510]; //cost为第二标尺
bool visited[510];
int pre[510];
int num1,num2,s,d;
void dijkstra(int start){
		dis[start]=0;
		cost[start]=0;  //起始位置的更新！
		for(int i =0;i<num1;i++){
		int u=-1,min=inf;
		for(int j=0;j<num1;j++){
			if(visited[j]==false && dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1)
		break;
		visited[u]=true;
		for(int v=0;v<num1;v++){
			if(G[v][u]!=inf&&visited[v]==false){
				if(dis[u]+G[v][u] < dis[v]){  //首先距离最小，第二标尺--花费最小
					dis[v] = dis[u]+G[v][u];
					cost[v] = cost[u]+c[u][v]; //不断去更新
					pre[v]=u; //记录前驱路径
				}
				else if(dis[u]+G[v][u] == dis[v]){
					if(c[u][v]+cost[u] < cost[v]){
						cost[v]=cost[u]+c[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
}
void dfs(int des){
	if(des == s){
		cout<< des<<" ";
		return;
	}
	dfs(pre[des]);
	cout<<des<<" ";
}
int main()
{
	cin>>num1>>num2>>s>>d;
	fill(G[0],G[0]+510*510,inf);
	fill(dis,dis+510,inf);
	fill(visited,visited+510,false);
	fill(c[0],c[0]+510*510,inf);
	for(int i=0;i<num2;i++){
		int e1,e2,l,co;
		cin>>e1>>e2>>l>>co;
		G[e1][e2] = G[e2][e1] = l;
		c[e1][e2] = c[e2][e1] = co;
	}
	for(int i=0;i<num1;i++)
	pre[i]=i;	
	dijkstra(s);
	dfs(d);
	cout<<dis[d]<<" "<<cost[d];
	return 0;
}
/*Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40
题目大意：求起点到终点的最短路径最短距离和花费，要求⾸首先路路径最短，其次花费最少，要输出完
整路径*/