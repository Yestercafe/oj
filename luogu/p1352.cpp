#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<bool> isNotRoot(n + 1);
	std::vector g(n + 1, std::vector<int>{});
	std::vector<bool> vis(n + 1);
	std::vector<std::array<int, 2>> f(n + 1, {0, 0});

	for (int i = 1; i <= n; ++i)
		std::cin >> f[i][1];

	for (int i = 1; i < n; ++i) {
		int a, b;
		std::cin >> a >> b;
		isNotRoot[a] = true;
		g[b].push_back(a);
	}

	std::function<void(int)> calc = [&](int k) {
		vis[k] = true;
		for (auto nxt : g[k]) {
			if (vis[nxt]) continue;
			calc(nxt);
			f[k][1] += f[nxt][0];
			f[k][0] += std::max(f[nxt][0], f[nxt][1]);
		}
	};

	for (int i = 1; i <= n; ++i) {
		if (!isNotRoot[i]) {
			calc(i);
			std::cout << std::max(f[i][0], f[i][1]) << std::endl;
			break;
		}
	}

	return 0;
}
