#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
int a[N];
int n;
void merge(int a[],int L1,int R1,int L2,int R2){  //两个序列合并
	//两个指针的感觉
	int i=L1,j=L2;
	int temp[N];
	int num=0;
	while(i<=R1&&j<=R2){
		if(a[i]<=a[j]) temp[num++]=a[i++]; 
		if(a[i]>a[j]) temp[num++]=a[j++];
	}
	while(i<=R1) temp[num++]=a[i++];
	while(j<=R2) temp[num++]=a[j++];
//	for(int x=0;x<num;x++)
//	a[L1+x]=temp[x];
	for(int i=L1,j=0;j<num;i++,j++) 
	a[i]=temp[j];
}
//	//递归版
//void merge_sort(int a[],int left,int right){
//	if(left>=right)
//	return;
//	int mid=left+right>>1;
//	merge_sort(a,left,mid);
//	merge_sort(a,mid+1,right); 
//	merge(a,left,mid,mid+1,right);
//}

//非递归版
void merge_sort(int a[]){
//	for(int step=2;step/2<=n;step*=2){ //每step个元素作为一组
//		for(int i=0;i<n;i+=step){ //对每一组 组内进行排序
//		int mid=i+step/2-1;
//		if(mid+1<n){  //下标从0开始你怎么办--就这么办
//		merge(a,i,mid,mid+1,min(i+step-1,n));	
//			}	
//		}
//	} 
	//欲输出每一趟归并的结果：
	for(int step=2;step/2<=n;step*=2){
		for(int i=0;i<n;i+=step){
			sort(a+i,a+min(i+step,n));
		}
		for(int j=0;j<n;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
//	merge_sort(a,0,n-1);
	merge_sort(a);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
/*
7
8 3 6 1 4 2 9
*/
