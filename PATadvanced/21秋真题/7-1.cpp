// h0​+i×sizeof(int)
//h1+i*sizeof(int)
//cin>>initial address&length
#include<iostream>
using namespace std;
typedef struct node{
	int initial;
	int num1;
}st;
st a[10010];
typedef long long ll;
int main()
{
	int n,k,max=0;
	cin>>n>>k;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i].initial>>a[i].num1;
		sum+=a[i].num1;
	}
	for(int i=0;i<k;i++){
		int temp=0,position=0;
		ll ans=0;
		cin>>temp;
		if(temp>=sum){
		cout<<"Illegal Access"<<endl;
		continue;}
		for(int j=0;j<n;j++){
			if(position+a[j].num1>temp){
				ans=a[j].initial+(temp-position)*4;
				cout<<ans<<endl;
				if(j>max) max=j;
				break;
			}
			position+=a[j].num1;
		}
	}
	cout<<max+1;
	return 0;
}
