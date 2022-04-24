#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e5;
typedef long long LL;
string fir,sec;
LL convert(string a,LL radix){
	LL num=0;
	int temp=0,index=0;
	for(auto it=a.rbegin();it!=a.rend();it++){
		temp=isdigit(*it)? *it-'0' : *it-'a'+10;
		num+=temp*pow(radix,index++);
	}
	return num;
}
LL find_radix(string b,LL tmp){
	char it=*max_element(b.begin(),b.end());
	LL low=(isdigit(it)? it-'0':it-'a'+10)+1;
	LL high=max(tmp,low);
	while(low<=high){
		LL mid=low+high>>1;
		LL t=convert(b,mid);
		if(t==tmp) return mid;
		else if(t<0||t>tmp) high=mid-1;
		else
		low=mid+1;
	}
	return -1;
}
int main(){
	int flag;
	LL radix1;
	cin>>fir>>sec>>flag>>radix1;
	LL ans=0;
	if(flag==1){
		ans=find_radix(sec,convert(fir,radix1));
	}
	else
		ans=find_radix(fir,convert(sec,radix1));
	if(ans==-1)
	cout<<"Impossible";
	else
	cout<<ans;
	return 0;
}