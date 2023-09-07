#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int a, b, c;
	std::cin >> a >> b >> c;

	int diff = std::abs(a - b);

	std::cout << int(ceil(diff * 1. / 2 / c)) << '\n';
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
