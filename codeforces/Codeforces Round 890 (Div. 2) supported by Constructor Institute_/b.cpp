#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		i64 sa = 0, sb = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			std::cin >> a;
			sa += a;
			sb += (a == 1 ? 2 : 1);
		}

		std::cout << (sa >= sb && n != 1 ? "YES" : "NO") << std::endl;
	}

	return 0;
}
