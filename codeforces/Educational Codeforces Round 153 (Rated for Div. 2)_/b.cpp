#include <bits/stdc++.h>
using i64 = long long;

int clamp(int a) {
	return std::clamp(a, 0, INT_MAX);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		int m, k, a1, ak;
		std::cin >> m >> k >> a1 >> ak;

		int nk = m / k - ak, n1 = m % k - a1;
		nk += n1 / k;
		n1 += k * std::abs(n1 / k);

		std::cout << clamp(n1) + clamp(nk) << std::endl;
	}

	return 0;
}
