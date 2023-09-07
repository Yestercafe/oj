#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	i64 n, x, y;
	std::cin >> n >> x >> y;
	const auto lcm = std::lcm(x, y);

	const auto cover = n / lcm;
	const auto uniq_x = n / x - cover;
	const auto uniq_y = n / y - cover;
	
	i64 med = 1;
	i64 a = uniq_x, b = 2 * n - uniq_x + 1;
	if (a % 2 == 0) {
		med = a / 2 * b;
	} else {
		med = a * (b / 2);
	}

	std::cout << med - uniq_y * (1 + uniq_y) / 2 << '\n';
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
