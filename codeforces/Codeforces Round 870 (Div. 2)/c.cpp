#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n, m;
	std::cin >> n >> m;
	if (m >= n) {
		m = n;
	}
	for (int k = 1; k <= m && k <= std::sqrt(m) + 1; ++k) {
		if (n % k == 0) {
			std::cout << "NO" << std::endl;
			return;
		}
	}
	std::cout << "YES" << std::endl;
}

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		sol();
	}
	return 0;
}

