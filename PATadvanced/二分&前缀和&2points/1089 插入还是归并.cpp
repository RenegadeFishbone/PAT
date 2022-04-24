#include<iostream>
#include<algorithm>
using namespace std;
const int N=10000;
int a[N],b[N],n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	scanf("%d",&b[i]);
	int i=0,j=0;
	while(b[i]<=b[i+1]&&i<n) i++;  //这里的问题，注意=号是可以取的--也是有序的
	j=i+1;
	while(b[j]==a[j]&&j<n) j++;
	if(j==n) {
	cout<<"Insertion Sort"<<endl;
	sort(a,a+i+2);
	for(int i=0;i<n;i++){
	if(i==0) cout<<a[i];
	else
	cout<<" "<<a[i];
	}
	}else{
		cout<<"Merge Sort"<<endl;
		int k = 1;
		bool flag = true;
		while(flag) {
		flag = false;
		for (i = 0; i < n; i++) {
		if (a[i] != b[i])
		flag = true;
		}
		k = k * 2;  //步长
		for (i = 0; i < n / k; i++)
		sort(a + i * k, a + (i + 1) * k);
		sort(a + n / k * k, a + n);  //排一下剩下的
		}
		for(int i=0;i<n;i++){
			if(i==0) cout<<a[i];
			else
			cout<<" "<<a[i];
		}
		}
		return 0;
}