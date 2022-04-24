#include<iostream>
#include<set>
#include<vector>
using namespace std;
int e[210][210]={0};
int nv,ne,ta,tb,dis,k;
int ans=99999,ansid=0;
void check(int index){
	int snum,sum=0;
	cin>>snum;
	vector<int> v(snum);
	set<int> s;
	for(int i=0;i<snum;i++)
	{
		cin>>v[i];
		s.insert(v[i]);
	}
	int flag=1; //是否tsp回路
	for(int i=0;i<snum-1;i++){
		if(e[v[i]][v[i+1]]==0) flag=0;
		sum+=e[v[i]][v[i+1]];
	}
	if(flag==0){
		printf("Path %d: NA (Not a TS cycle)\n",index);
	}
	else if(v[0]!=v[snum-1] || s.size()!=nv){
		printf("Path %d: %d (Not a TS cycle)\n",index,sum);
	}
	else if(snum==nv+1){
		printf("Path %d: %d (TS simple cycle)\n",index,sum);
		if(sum<ans){
			ans=sum;
			ansid=index;
		}
	}
	else{
	    printf("Path %d: %d (TS cycle)\n",index,sum);
	    if(sum<ans){
	    	ans=sum;
	    	ansid=index;
		}
	}
}
int main()
{
	cin>>nv>>ne;
	for(int i=0;i<ne;i++){
		cin>>ta>>tb>>dis;
		e[ta][tb]=e[tb][ta]=dis;
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		check(i);
	}
	cout<<"Shortest Dist("<<ansid<<") = "<<ans;
}