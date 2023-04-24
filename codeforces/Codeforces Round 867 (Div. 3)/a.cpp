#include <bits/stdc++.h>
using i64 = long long;

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		int n, t;
		std::cin >> n >> t;
		std::vector<std::pair<int, int>> v(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> v[i].first;
		}
		for (int i = 0; i < n; ++i) {
			std::cin >> v[i].second;
		}

		int spent = 0;
		int ma = -1, mi = -1;
		for (int i = 0; i < n; ++i) {
			if (spent + v[i].first <= t) {
				if (ma < v[i].second) {
					ma = v[i].second;
					mi = i;
				}
			}
			++spent;
		}

		std::cout << (mi < 0 ? -1 : mi + 1) << std::endl;
	}
	return 0;
}
