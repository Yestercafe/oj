#include <bits/stdc++.h>
using i64 = long long;

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::vector<i64> v(n);
		for (int i = 0; i < n; ++i)
			std::cin >> v[i];

		std::sort(v.begin(), v.end());

		std::cout << std::max(v[0] * v[1], *(v.end() - 1) * *(v.end() - 2)) << std::endl;
	}
	return 0;
}
