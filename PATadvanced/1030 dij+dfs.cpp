#include<iostream>
#include<algorithm>
#include<vector>
#define inf 999999
using namespace std;
int e[510][510],cost[510][510],dis[510];
bool visit[510];
vector<int> pre[510];   //dijkstra生成---可能不止一条，现在是一个二维的动态数组 
vector<int> temppath,path; //dfs搜索出来的结果
int n,m,start,destination;  //点数目 边数 起点 终点 
int mincost = inf;
void dfs(int des)
{
	temppath.push_back(des); //关于路径的存储
	if(des == start){
		int tempcost = 0;
		for(int i = temppath.size()-1; i>0; i--){
		int edge1 = temppath[i],edge2 = temppath[i-1];
		tempcost += cost[edge1][edge2];
		}
		if(tempcost < mincost){
			mincost = tempcost;
			path = temppath; //同类型直接赋值
		}
		temppath.pop_back();  //回退？？
		return;
	}
	for(int i = 0; i < pre[des].size(); i++){  //不止一条路
		dfs(pre[des][i]);
	} 
	temppath.pop_back();
}
int main()
{
	cin >> n >> m >> start >> destination;
	fill(e[0],e[0]+510*510,inf);
    fill(dis,dis+510,inf);
	fill(visit,visit+510,false);
	for(int i =0; i < m; i++){
		int a,b,dist2,cost2;
		cin >> a >> b >> dist2 >> cost2;
		e[a][b] = dist2;
		e[b][a] = dist2;
		cost[a][b] = cost2;
		cost[b][a] = cost2;
	}
	//dijkstra算法部分
	pre[start].push_back(-1);
	dis[start] = 0; //开始就选起点蛤
	for(int i = 0; i < n; i++){
		int u = -1,min = inf;
		for(int j = 0; j < n; j++){ //顶点是从0开始标号的 
			if(visit[j] == false && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		if(u == -1)
		break;
		visit[u] = true;
		for(int j = 0; j < n; j++){
			if(visit[j] == false && e[j][u] != inf){ //遍历未收录的邻接点 
				if(dis[u] + e[u][j] < dis[j]){
					dis[j] = dis[u] + e[u][j];
					pre[j].clear();  //唯一最短路 --最! !
					pre[j].push_back(u);
				} 
				else if(dis[u] + e[u][j] == dis[j]){  //比起经典dij新增 
					pre[j].push_back(u);//路径可能不唯一--使用二维向量 
				}
			}
		}
	}	
	dfs(destination); //搜索最小代价路径
	for(int i = path.size() - 1; i>=0; i--)  //倒着存的，倒着输出
	cout << path[i] << " ";
	cout << dis[destination] << " " << mincost;  
    return 0; 
}
