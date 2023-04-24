#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using i64 = long long;

i64 n, k, c;
std::vector<std::vector<int>> g;
std::vector<bool> vis;

i64 bfs(int st) {
	vis.clear();
	vis.resize(n + 1);
	std::queue<int> q;
	vis[1] = true;
	vis[st] = true;
	q.push(st);
	int depth = 0;
	while (!q.empty()) {
		int s = q.size();
		while (s--) {
			auto fr = q.front();
			q.pop();
			for (auto nxt : g[fr]) {
				if (vis[nxt]) continue;
				vis[nxt] = true;
				q.push(nxt);
			}
		}
		++depth;
	}
	return depth;
}

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		std::cin >> n >> k >> c;
		vis.clear();
		vis.resize(n + 1);

		g.clear();
		g.resize(n + 1);
		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			std::cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		i64 l1 = 0, l2 = 0;
		for (auto nxt : g[1]) {
			auto l = bfs(nxt);
			if (l > l1) {
				l2 = l1;
				l1 = l;
			} else if (l > l2) {
				l2 = l;
			}
		}
		
		if (k > c) {
			std::cout << k * l1 + (k - c) * l2 << std::endl;
		} else {
			std::cout << k * l1 << std::endl;
		}
	}
	return 0;
}
