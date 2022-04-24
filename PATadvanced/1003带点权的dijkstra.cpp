#include<iostream>
#include<algorithm>
#define inf 999999
using namespace std;
int dist[510],num[510],weight[510],w[510]; //dist--������� num--ͳ�����·���� weight--��Ȩֵ w--�����Ȩ 
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
	dist[s]=0;//���
	w[s] = weight[s]; 
	num[s] = 1;
	//dijkstra
	for(int i=0;i<n;i++){
		int u=-1,minn=inf;
		for(int j=0;j<n;j++){
			if(visit[j]==false && dist[j]<minn){
				minn = dist[j];     //�Ҵ�ʱdist[]��Сֵ 
				u = j;
			}
		}
		if(u == -1)
		break; //ȫ���Ѿ���¼
		visit[u] = true;
		for(int j=0;j<n;j++){
			if(e[u][j] != inf && visit[j] == false){ //�ڽ�&&û�б����ʹ� 
			if(dist[j] > dist[u] + e[u][j]){
				dist[j] = dist[u]+e[u][j];
				num[j] = num[u]; //? 
				w[j] = w[u]+weight[j]; //��Ȩֵ�� 
			} 
			else if(dist[j] == dist[u]+e[u][j]){
				num[j] += num[u]; //�ǼӺͲ��Ǽ�++
				if(w[j] < w[u]+weight[j]){
					w[j] = w[u] + weight[j]; //��Ȩ���ֵ 
				} 
			}	
			}
		} 
	}
	cout << num[d] << " " << w[d];
	return 0;
}
