#include<iostream>
using namespace std;
const int N=100010;
int a[N];
int n;
void Insert_Sort(int a[],int n){
	for(int i=1;i<n;i++){
		int j=i;
		while(a[j]<a[j-1]&&j>=0){
			swap(a[j],a[j-1]);
			j--;
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	Insert_Sort(a,n);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
/*
8
1 9 2 6 7 4 3 8
*/