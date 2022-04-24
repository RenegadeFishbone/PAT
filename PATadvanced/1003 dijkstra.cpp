#include<iostream>
#include<algorithm>
#define inf 999999
int dist[510],num[510],weight[510],w[510];
int e[510][510];
bool visit[510];
using namespace std;
int main()
{
	fill(visit,visit+510,false);
	fill(dist,dist+510,inf);
	fill(e[0],e[0]+510*510,inf);
	int n,m,s,d;
	cin >> n >> m >> s >>d;
	for(int  i = 0; i < n; i++){
		int tempw; cin>>tempw;
		weight[i] = tempw;
	}
	for(int i = 0; i < m; i++){
		int a,b,cost;
		cin >> a >> b >>cost;
		e[a][b] = e[b][a] = cost;
	}
	dist[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for(int i = 0; i < n; i++){
		int u = -1,minn = inf;
		for(int j = 0; j < n; j++){
			if(visit[j] == false && dist[j] < minn){
				minn = dist[j];
				u = j;
			}
		}
		if(u == -1)
		break;
		visit[u] = true;
		for(int j = 0; j < n; j++){
			if(e[u][j] != inf && visit[j] == false){
				if(dist[j] > dist[u] + e[u][j]){
					//更新 
					dist[j] = dist[u] + e[u][j];
					num[j] = num[u];
					w[j] = w[u] + weight[j];
				}
				else if(dist[j] == dist[u] + e[u][j]) {
					num[j] += num[u];  //最短路径数量
					if(w[u] + weight[j] > w[j]){
						w[j] = w[u] + weight[j];
					}
				}
			}
		}
	}
	cout << num[d] << " " << w[d];
	return 0;
}
