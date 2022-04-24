#include<iostream>
#include<algorithm>
#include<queue> 
using namespace std;
int a[100][100];
int visited[100];
int n,m;
queue<int> b;
void DFS(int s){
	cout << s << " ";
	visited[s] = 1;
	for(int i = 0; i < n; i++){
	if(visited[i] == 0 && a[i][s] == 1){
		DFS(i);
	}		
	}
}
void BFS(int s){
	visited[s] = 1;
	b.push(s);
	while(1){
		if(b.empty())
		return;
		else{
			int c = b.front();
			b.pop();
			cout << c << " " ;
			for(int j = 0; j < n; j++){
				if(visited[j] == 0 && a[j][c]){
					b.push(j);
					visited[j] = 1;
				}
			}
		}
	}
}
int main()
{
	fill(visited,visited+100,0);
	fill(a[0],a[0]+100*100,0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1; 
	}
	int flag = true;
	for(int i = 0; i < n; i++){
		if(visited[i] == 0){
			cout << "{ ";
			flag = false; 
			DFS(i);
		}
		if(flag == false){
			cout << "}" << endl;
			flag = true;
		}
	}
	fill(visited,visited+100,0);
	for(int i = 0;i < n; i++){
		if(visited[i] == 0){
			cout << "{ ";
			flag = false;
			BFS(i); 
		}
		if(flag == false){
			cout << "}" << endl;
			flag = true;
		}
	}
	return 0;
}
