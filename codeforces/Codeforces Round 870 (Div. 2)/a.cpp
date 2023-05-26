#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}

	for (int ans = 0; ans <= n; ++ans) {
		int liars = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i] > ans) {
				++liars;
			}
		}
		if (ans == liars) {
			std::cout << ans << std::endl;
			return;
		}
	}
	std::cout << -1 << std::endl;
}

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		sol();
	}
	return 0;
}
