#include<iostream>
using namespace std;
const int maxn=10010;
int fa[maxn]={0};
int cnt[maxn]={0};
bool exist[maxn];
int n,m,k;
void init();
int find(int x)
{
	if(x==fa[x])
	return x;
	else{
		int temp=find(fa[x]); //路径压缩
		fa[x] = temp;
		return temp;
	}
}
void merge(int a,int b){
	int fathera=find(a);
	int fatherb=find(b);
	if(fathera!=fatherb)
	fa[fathera]=fatherb;
}
int main()
{
	cin>>n;
	for(int i=1;i<=maxn;i++){
		fa[i]=i;
	}
	int id,temp;
	for(int i=0;i<n;i++){
		cin>>k>>id;
		exist[id]=true;
		for(int j=1;j<=k-1;j++){
			cin>>temp;
			merge(id,temp);  //把一个照片中的鸟合并至一个树上
			exist[temp]=true;
		}
	}
	for(int i=1;i<=maxn;i++){
		if(exist[i]){
			int root = find(i);
			cnt[root]++;
		}
	}
	int numTrees=0,numBirds=0;
	for(int i=1;i<=maxn;i++){
		if(exist[i] && cnt[i]!=0){
			numTrees++;
			numBirds+=cnt[i];
		}
	}
	cout<<numTrees<<" "<<numBirds<<endl;
	cin>>m;
	int ida,idb;
	for(int i=0;i<m;i++){
		cin>>ida>>idb;
		printf("%s\n",(find(ida)==find(idb))?"Yes":"No");
	}
	return 0;
}