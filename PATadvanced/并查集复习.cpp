#include<iostream>
using namespace std;
int father[100];
int ans2 = 0;
void init()
{
	for(int i = 1; i < 100; i++)
	father[i] = i;
}
//int find(int x)
//{
//	if(x == father[x])
//	return x;
//	else{
//		int temp = find(father[x]);
//		father[x] = temp;
//		return temp; //路径压缩 
//	}
//}
//最初版
//int find(int x){
//	if(x==father[x])
//	return x;
//	else{
//		return find(father[x]);  
//	}
//}
//路径压缩
int find(int x){
	if(x==father[x])
	return x;
	else{
		father[x]=find(father[x]);  //三声爹
		return father[x];
	}
}
void merge(int x,int y)
{
	int p = find(x);
	int q = find(y);
	if(p != q){
		father[p] = q;
		ans2++;
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	init();
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		merge(a,b);
	}
	//每做一次Merge就减去总人数emmm好像也可以 
	//怎么去查有多少分组呢----路径压缩--每个集合只有一个根节点（树的性质）并且集合中所有的顶点的爹都已经是根
//	int ans = 0;
//	for(int i = 1; i <= n; i++){
//		if(i == father[i])
//		ans++;
//	} 
//	cout << ans;
    cout<< n-ans2;
	return 0;
}
/*测试数据
7 5 
1 2
2 3
3 1
1 4
5 6

out: 3
*/ 
