#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int e[210][210];
int main()
{
	fill(e[0],e[0]+210,0);
	int nv,ne;
	cin>>nv>>ne;
	for(int i=0;i<ne;i++){
		int a,b;
		cin>>a>>b;
		e[a][b]=1;
		e[b][a]=1;
	}
	int num; cin>>num;
	int k;
	for(int i=0;i<num;i++){
		bool isClique=true,isMaximal=true;
		int hash[210]={0};
		cin>>k;
		vector<int> v(k);
		for(int j=0;j<k;j++){
			cin>>v[j];
			hash[v[j]]=1; //标记
		}
		for(int j=0;j<k;j++){
			if(!isClique) break;
			for(int l=j+1;l<k;l++){
				if(e[v[j]][v[l]]==0){
					isClique=false;
					cout<<"Not a Clique"<<endl;
					break;					
				}
			}
		}
		if(!isClique) continue; //不用继续了
		for(int j=1;j<=nv;j++){ //从1开始编号，遍历全部顶点
			if(hash[j]==0){
				for(int l=0;l<k;l++){
					if(e[v[l]][j]==0) break;//加不了了--不连接
					if(l==k-1) isMaximal=false;//还可以继续加
				}
			}
			if(isMaximal==false){
				cout<<"Not Maximal"<<endl;
				break;
			}
		}
		if(isMaximal) cout<<"Yes"<<endl;
		}
		return 0;}