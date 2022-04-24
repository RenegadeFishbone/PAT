// always choose the next destination with the smallest number
//ind the best starting spot so they can explore as many spots as they can.
#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m, a, b;
int ans = 1, maxSpots = 1;
vector<int> g[maxn];
bool vis[maxn];
int dfs(int u) {
	vis[u] = true;
	int tmpSpots = 0;
	for (int v : g[u]) {
		if (vis[v] == false) {
			tmpSpots = dfs(v); // 只探索未访问过的、编号最小的结点
			break;
		}
	}
	vis[u] = false;
	return 1 + tmpSpots;
}
int main() {
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
	for (int i = 1; i <= n; ++i) {
		int spots = dfs(i);
		if (spots > maxSpots) {
			maxSpots = spots;
			ans = i;
		}
	}
	cout << ans << " " << maxSpots;
	return 0;
}

