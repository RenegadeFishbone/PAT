#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
const int inf=0x3fffffff;
const int MAXV = 510;
struct Node{
	int v,dis;
	Node(int _v,int _dis) : v(_v),dis(_dis) {};//构造函数
	};
	vector<Node> adj[MAXV]; //邻接表表示法
	int n,m,st,ed,weight[MAXV];
	int d[MAXV],w[MAXV],num[MAXV];
	set<int> pre[MAXV];
	bool Bellman(int s){ //核心算法
		fill(d,d+MAXV,inf);
		memset(num,0,sizeof(num));
		memset(w,0,sizeof(w));
		d[s]=0;  //s--start
		w[s]=weight[s];
		num[s]=1;
		for(int i=0;i<n-1;i++){
			for(int u=0;u<n;u++){  //每轮操作都遍历所有边
				for(int j=0;j<adj[u].size();j++){
					int v =adj[u][j].v;
					int dis=adj[u][j].dis;
					if(d[u]+dis<d[v]){
						d[v]=d[u]+dis;
						w[v]=w[u]+weight[v];
						num[v]=num[u];
						pre[v].clear();
						pre[v].insert(u);
					}
					else if(d[u]+dis==d[v]){
						if(w[u]+weight[v]>w[v]){
							w[v]=w[u]+weight[v];
						}
						pre[v].insert(u);
						num[v]=0;
						set<int>::iterator it;
						for(it = pre[v].begin();it != pre[v].end();it++){
							num[v]+=num[*it];
						}
					}
				}
			}
		}
	}
	int main(){
		cin>>n>>m>>st>>ed;
		for(int i=0;i<n;i++){
			cin>>weight[i];//点权
		}
		int u,v,wt;
		for(int i=0;i<m;i++){
			cin>>u>>v>>wt;
			adj[u].push_back(Node(v,wt));
			adj[v].push_back(Node(u,wt));
		}
		Bellman(st);
		cout<<num[ed]<<" "<<w[ed]; //路径数量&最短路径权重
		return 0;
	}