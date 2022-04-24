#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
const int inf = 999999999;
int e[205][205], weight[205], dis[205];
bool visit[205];
vector<int> pre[205], temppath, path;   //pre---dijkstra得出 
map<string, int> m;
map<int, string> m2;
int maxvalue = 0, mindepth, cntpath = 0;  //记录dfs中的答案 
double maxavg;
void dfs(int v) {   //DFS
temppath.push_back(v);
if(v == 1) {  //如果搜到了起点---结束了 
int value = 0;
for(int i = 0; i < temppath.size(); i++) {
value += weight[temppath[i]];  //weight就是happiness值 
}
double tempavg = 1.0 * value / (temppath.size() - 1); //细节 
if(value > maxvalue) {
maxvalue = value;
maxavg = tempavg;
path = temppath;
} else if(value == maxvalue && tempavg > maxavg) {
maxavg = tempavg;
path = temppath;
}
temppath.pop_back();
cntpath++;
return ;
}
for(int i = 0; i < pre[v].size(); i++) {  //有几条路搜几遍？ 
dfs(pre[v][i]);
}
temppath.pop_back();
}
int main() {
fill(e[0], e[0] + 205 * 205, inf);
fill(dis, dis + 205, inf);
scanf("%d %d", &n, &k);
string s;
cin >> s;  //起点 
m[s] = 1;   //映射值 --仅对应城镇名字和编号 
m2[1] = s;
for(int i = 1; i < n; i++) {
cin >> s >> weight[i+1];  //幸福值 
m[s] = i+1;
m2[i+1] = s;
}
string sa, sb;  //cost录入 
int temp;
for(int i = 0; i < k; i++) {
cin >> sa >> sb >> temp;
e[m[sa]][m[sb]] = temp;  //666
e[m[sb]][m[sa]] = temp;
}
dis[1] = 0;
for(int i = 0; i < n; i++) { //dijkstra 
int u = -1, minn = inf;
for(int j = 1; j <= n; j++) {  //找最小点
if(visit[j] == false && dis[j] < minn) {
u = j;
minn = dis[j];    
}
}
if(u == -1) break;  //找不到 
visit[u] = true;  
for(int v = 1; v <= n; v++) {   
if(visit[v] == false && e[u][v] != inf) {   //你需要模拟一下--画一画 
if(dis[u] + e[u][v] < dis[v]) { 
dis[v] = dis[u] + e[u][v];
pre[v].clear();  //改变路线(有更短的) --- size = 0 
pre[v].push_back(u); //反向Path，不用回溯了 （？） 
} else if(dis[v] == dis[u] + e[u][v]) {
pre[v].push_back(u);   //(一样短的， //vector[][]可以存好几条就是说 ——--完成了dij存多条路径的任务 )
}
}
}
}
int rom = m["ROM"];  //值 
dfs(rom);  //从Rome(destination)开始搜索权值最大的路 ---如果有多条最短路径的话 
printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);  //
for(int i = path.size() - 1; i >= 1; i--) {
cout << m2[path[i]] << "->";
}
cout << "ROM";
return 0;
}
