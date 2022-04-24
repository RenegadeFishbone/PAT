#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
vector<vector<int>> v;
set<int> s;
vector<int> temp;
int visited[1000];
int height = 1,maxheight = 0;
int n;
void dfs(int s,int height){
	if(height > maxheight){
		maxheight = height;
		temp.clear();
		temp.push_back(s);
	}
	else if(height == maxheight){
		temp.push_back(s);
	}
	visited[s] = 1;
	for(int i = 0; i < v[s].size(); i++){
		if(visited[v[s][i]] == 0)
		dfs(v[s][i],height+1);  //��¼�ݹ��� 
	}
}
int main(){
	cin >> n;
	v.resize(n+1); // ��Ȼ���Ƕ�̬�ĵ���ֻ��һ��һ���ӣ��������Ҫ��ʼ�� 
  	for(int i = 0; i< n-1; i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int count = 0;
	int start;
	for(int i = 1; i <= n; i++){
		if(visited[i] == 0)
		{
		dfs(i,1);
		start = temp[0]; // ��¼һ������ڵ� 
		count ++; //��ͨ�Ļ��Ͳ�����õڶ��� 
	    }
	}
	if(count != 1){
		cout << "Error: " << count << " components";
		return 0;
	}
	else{
		for(int i = 0; i < temp.size(); i++){
			s.insert(temp[i]);
		}
		fill(visited,visited+1000,0);
		temp.clear(); 
		dfs(start,1);
		for(int i = 0; i < temp.size(); i++){
			s.insert(temp[i]);
		}
		for(auto it = s.begin(); it != s.end(); it++){
			cout << *it << endl;
		}
	}
	return 0;
}
