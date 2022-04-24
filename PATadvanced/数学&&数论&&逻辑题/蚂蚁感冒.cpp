#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=60;
int a[N];
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int left=0,right=0;
	for(int i=0;i<n;i++){
		 if(abs(a[i])>abs(a[0])&&a[i]<0)
		 right++;
		 if(abs(a[i])<abs(a[0])&&a[i]>0)
		 left++;
//		 if(a[0]<0&&abs(a[i])<abs(a[0])&&a[i]>0)
//		 left++;
//		 if(a[0]<0&&abs(a[i])>abs(a[0])&&a[i]<0)
//		 right++;
	}
	if((a[0]>0&&right==0)||(a[0]<0&&left==0))  //特判
	cout<<1;
	else
	cout<<left+right+1;
}