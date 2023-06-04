#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;
	int p1, p2, pn;
	std::vector<int> arr(n + 1);
	for (int i = 1; i <= n; ++i) {
		int a;
		std::cin >> a;
		arr[i] = a;
		if (a == 1) p1 = i;
		if (a == 2) p2 = i;
		if (a == n) pn = i;
	}

	if (n < 3) {
		std::cout << "1 1" << std::endl;
		return;
	}
	if (-1 <= p1 - p2 && p1 - p2 <= 1) {
		if (p1 < pn && p1 < p2) {
			std::cout << p2 << ' ' << n << std::endl;
		} else if (pn < p1 && p2 < p1) {
			std::cout << p2 << ' ' << 1 << std::endl;
		} else {
			std::cout << p1 << ' ' << pn << std::endl;
		}
		return;
	}

	if (p1 < p2) {
		std::cout << pn << ' ' << p1 + 1 << std::endl;
	} else {
		std::cout << pn << ' ' << p1 - 1 << std::endl;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int tt;
	std::cin >> tt;
	while (tt--) {
		::sol();
	}
	return 0;
}
