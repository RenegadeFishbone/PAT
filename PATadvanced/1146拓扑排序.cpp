#include<iostream>
#include<vector>
using namespace std;
vector<int> graph[1010];
int degree[10010];
int main(){
	int nv,ne,k;
	int ta,tb;
	int flag=0;
	cin>>nv>>ne;
	for(int i=0;i<ne;i++){
		cin>>ta>>tb;
		graph[ta].push_back(tb);
		degree[tb]++;
	}
	cin>>k;
	for(int i=0;i<k;i++){
		int judge=1;
		    vector<int> tin(degree,degree+nv+1);
		for(int j=0;j<nv;j++){
			int v;
			cin>>v;
			if(tin[v]!=0){
			judge=0;
		}
			for(int it : graph[v]) tin[it]--;
			}
			if(judge)
			continue;
			printf("%s%d",flag == 1? " ":"",i);
			flag=1; //
	}
	return 0;	
}
