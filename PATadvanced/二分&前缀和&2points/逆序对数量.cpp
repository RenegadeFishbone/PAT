#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010;
int n,tmp[N];
int a[N];
typedef long long LL;
LL res;
LL merge_sort(int a[],int l,int r){
	if(l>=r) return 0;
	int mid=l+r>>1;
	res=merge_sort(a,l,mid)+merge_sort(a,mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]) tmp[k++]=a[i++];
		else{
			res+=mid+1-i;
			tmp[k++]=a[j++];
		}
	}
	while(i<=mid) tmp[k++]=a[i++];
	while(j<=r) tmp[k++]=a[j++];
	for(int i=l,k=0;i<=r;i++,k++) a[i]=tmp[k];
	return res;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	cout<<merge_sort(a,0,n-1);
	return 0;
}