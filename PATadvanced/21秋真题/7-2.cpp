//heavier one wears larger hat.
//cout:  indices of the hat owners in the order of picking up their hats
//sort how to do? the indices of orders
#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct hat{
	int size;
	int num1;
};
struct folk{
	int weight;
	int num2;
	int order;
};
typedef struct hat hh;
typedef struct folk fk;
const int N=10010;
bool cmp1(hh a,hh b){
	return (a.size>b.size);
}
bool cmp2(fk a,fk b){
	return (a.weight>b.weight);
}
hh hat[N],hat1[N];
fk folk[N],folk1[N];
//map的用法？---排序后还要保留序号，怎么办
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>hat[i].size;
	}
	for(int i=0;i<n;i++)
	cin>>folk[i].weight;
	memcpy(hat1,hat,sizeof hat);
	memcpy(folk1,folk,sizeof folk);
	sort(hat1,hat1+n,cmp1);
	sort(folk1,folk1+n,cmp2);
	for(int i=0;i<n;i++){
		hat1[i].num1=i+1;
	}
	for(int i=0;i<n;i++){
		folk1[i].num2=i+1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(hat1[i].size==hat[j].size){
				hat[j].num1=hat1[i].num1;
				break;
			}
		}
	}
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(folk1[i].weight==folk[j].weight){
				folk[j].num2=folk1[i].num2;
				break;
			}
		}
	}
	int order1=0;
	for(int j=n-1;j>=0;j--){
		order1++;
		for(int i=0;i<n;i++){
			if(hat[j].num1==folk[i].num2){
				folk[i].order=order1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(i==folk[j].order){
				if(i==1)
				printf("%d",j+1);
				else
				printf(" %d",j+1);
			}
		}
	}
//	for(int i=0;i<n;i++){
//		if(i==0)
//		printf("%d",folk[i].order);
//		else
//		printf(" %d",folk[i].order);
//	}
	return 0;
}