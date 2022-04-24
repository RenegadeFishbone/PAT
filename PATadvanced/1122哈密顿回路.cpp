#include<iostream>
#include<vector>
#include<set>
using namespace std;
int e[210][210];
int nv,ne,k,knum;
int main()
{
	cin>>nv>>ne;
	for(int i=0;i<ne;i++){
		int ta,tb;
		cin>>ta>>tb;
		e[ta][tb]=e[tb][ta]=1;
	}
	cin>>k;
	while(k--){
		cin>>knum;
		vector<int> v(knum);
		set<int> s;
		for(int i=0;i<knum;i++){
			cin>>v[i];
			s.insert(v[i]);
		}
		int flag1=1,flag2=1;
		if(s.size()!=nv || knum!=nv+1 || v[0]!=v[knum-1])
		flag1=0;
		for(int i=0;i<knum-1;i++){
			if(e[v[i]][v[i+1]]==0)
			{
				flag2=0; break;
			}
		}
		if(flag1&&flag2)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}