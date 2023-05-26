#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int x, k;
	std::cin >> x >> k;

	std::vector f(x + 1, std::vector<int>{});
	for (int i = 1; i <= x; ++i) {
		int minj = -1, min = INT_MAX;
		for (int j = 1; j <= i; ++j) {
			if (j % k == 0) continue;
			if (min > f[i - j].size()) {
				minj = j;
				min = f[i - j].size();
			}
		}
		f[i] = f[i - minj];
		f[i].push_back(minj);
	}

	auto& ans = f.back();
	int n = ans.size();
	std::cout << n << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		::sol();
	}
	return 0;
}
