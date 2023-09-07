#include <bits/stdc++.h>
using i64 = long long;

void fact(int a) {
	for (int f = 2; f <= a / f; ++f) {
		if (a % f == 0 && a - f != 1) {
			std::cout << f << ' ' << a - f << std::endl;
			return;
		}
	}
	std::cout << -1 << std::endl;
}

void sol() {
	int l, r;
	std::cin >> l >> r;
	if (l > r) std::swap(l, r);

	if (r < 4) {
		std::cout << -1 << '\n';
		return;
	}

	if (r % 2 == 0) {
		std::cout << 2 << ' ' << r - 2 << std::endl;
	} else {
		if (r == l) {
			fact(r);
			return;
		}
		std::cout << 2 << ' ' << r - 3 << std::endl;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--) {
		sol();
	}

	return 0;
}
