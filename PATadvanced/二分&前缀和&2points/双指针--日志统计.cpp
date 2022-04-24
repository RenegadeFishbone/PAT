#include<iostream>
#include<algorithm>
#include<cstdio>
#define x first
#define y second
using namespace std;
int n,d,k;
const int N=100010;
typedef pair<int,int> PII;
int cnt[N];
bool st[N];
PII logs[N];
int main(){
	cin>>n>>d>>k;
	for(int i=0;i<n;i++)
	scanf("%d%d",&logs[i].x,&logs[i].y);
	sort(logs,logs+n); //按第一关键字排序--时间顺序
	for(int i=0,j=0;i<n;i++) //双指针思想
	{
		int id=logs[i].y;
		cnt[id]++;
		//此刻可能有之前帖子的点赞不算数了
		while(logs[i].x-logs[j].x>=d){  //左闭右开区间
			cnt[logs[j].y]--;
			j++; //遍历日志
		}
		if(cnt[id]>=k) st[id]=true; //当前日志
	}
	for(int i=0;i<=100000;i++){
		if(st[i])
		printf("%d\n",i);
	}
	return 0;
}



