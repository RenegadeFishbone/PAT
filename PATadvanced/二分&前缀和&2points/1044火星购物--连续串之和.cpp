#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=100010;
int a[N];
typedef long long LL;
LL s[N];	
map<int,int> res;
map<int,int> temp;
int main(){
	int n,total,min=0x3f3f3f3f;
	cin>>n>>total;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]+=s[i-1]+a[i];  
	}
	int l=0,r=0,sum=0;
	while(l<=n&&r<=n){
		sum=s[r]-s[l];
		if(sum<total){
			r++;
		}else if(sum>total){
			if(min!=total){  //只能退而求其次咯
				if(sum<min){
					min=sum; //存储更小的
					temp.clear();
					temp[l]=r;//存储的可能二元组清除
				}else if(sum==min){
					temp[l]=r;//二元组++
				}
			}
			l++;
		}
		else{
			res[l]=r;
			min=total;
			r++;
		}
	}
	if(min==total){
		for(auto s:res)
			printf("%d-%d\n",s.first+1,s.second);
	}
	else{
		for(auto s:temp)
			printf("%d-%d\n",s.first+1,s.second);
	}
	return 0;
}

