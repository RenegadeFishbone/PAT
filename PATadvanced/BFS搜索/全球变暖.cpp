#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define x first
#define y second
using namespace std;
const int N=1010;
int n,ans;
char g[N][N];
int vis[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
typedef pair<int,int> PII;
void bfs(int x,int y){
	int num=0;//岛屿会不会被淹没--是否所有#都临海
	int snum=0;
	queue<PII> q;
	q.push({x,y});
	vis[x][y]=1;
	while(q.size()){
		bool flag=false;
		auto t=q.front();
		q.pop();
		num++;
		for(int i=0;i<4;i++){
			int cx=dx[i]+t.x,cy=dy[i]+t.y;
			if(cx>=0&&cy>=0&&cx<n&&cy<n&&!vis[cx][cy]&&g[cx][cy]=='#'){
				q.push({cx,cy});
				vis[cx][cy]=1;
			}
			else if(cx>=0&&cy>=0&&cx<n&&cy<n&&!vis[cx][cy]&&g[cx][cy]=='.'){
				//临海板块
				flag=true;
			}
			}
		if(flag) snum++;		
		}
		if(num==snum)
		ans++;
}
int main(){
	cin>>n;
	int cnt=0; //连通集的数量
	for(int i=0;i<n;i++) scanf("%s",g[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//宽搜得到连通集数量
			if(!vis[i][j]&&g[i][j]=='#'){
				bfs(i,j);
				cnt++;
			}
		}
	}
	cout<<ans;  //统计连通集
}