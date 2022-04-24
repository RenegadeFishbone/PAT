#include<iostream>
#include<cstdio>
using namespace std;
const int N=100100;
double a[N],s[N];
int main(){
	int n;
	cin>>n;
	double ans=0.0,tmp;
//	for(int i=1;i<=n;i++){
//		scanf("%lf",&a[i]);
//		s[i]=s[i-1]+a[i]; //前缀和 o(n^2)超时啦
//		ans+=a[i];
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++)
//		ans+=s[j]-s[i-1];
//	}
	for(int i=1;i<=n;i++){
		cin>>tmp;
		ans+=tmp*i*(n-i+1);  //一点规律---O(N)
	}
	printf("%.2lf",ans);
	return 0;
}
