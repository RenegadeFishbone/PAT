#include<iostream>
#include<vector>
using namespace std;
int e[210][210];
int main(){
	int nv,ne,tempa,tempb;
	cin>>nv>>ne;
	for(int i=0;i<ne;i++){
		cin>>tempa>>tempb;
		e[tempa][tempb]=e[tempb][tempa]=1;
	}
	int num,k;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>k; //测试组顶点数
		vector<int> v(k);
		int hash[210]={0},isclique=1,ismaximal=1;
		for(int j=0;j<k;j++){
			cin>>v[j];
			hash[v[j]]=1;
		}
		for(int j=0;j<k;j++){
			if(isclique==0)
			break;
			for(int l=j+1;l<k;l++){
				if(e[v[j]][v[l]]==0){
					isclique=0; //不相连
					cout<<"Not a Clique"<<endl;
					break;
				}
			}
		}
		if(isclique==0)
		continue;
		for(int j=1;j<=nv;j++){
			if(hash[j]==0){
				for(int l=0;l<k;l++){
					if(e[v[l]][j]==0) break; //只要有点不相邻说明不在该团中
					if(l==k-1) ismaximal=0;
				}
			}
		}
		if(ismaximal==0){
		cout<<"Not Maximal"<<endl;
	}
		if(ismaximal)
		cout <<"Yes"<<endl;
	}
}