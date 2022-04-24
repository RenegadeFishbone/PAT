#include<iostream>
using namespace std;
int visited[10000]; 
int v[1000][1000];
int n,m,k; 
void dfs(int s){
	visited[s] = 1;
	for(int i = 1; i <= n; i++){
		if(visited[i] == 0 && v[i][s] == 1){
			dfs(i);
		}
	}
}
int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int a,b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	for(int i = 0; i < k; i++){
		fill(visited,visited+10000,0);  //没次拆的都要更新--在循环里面OAO啊啊 
		int a;
		cin >> a;
		int cnt = 0;
		visited[a] = 1;  //被占领 --- “切断”--你搜不了了啊
		for(int j = 1; j <= n; j++){
			if(visited[j] == 0){
				dfs(j);
				cnt++;
			}
		}
		if(cnt == 0)
		cout << cnt << endl;
		else 
		cout << cnt-1 <<endl; 
	}
	return 0;
}
