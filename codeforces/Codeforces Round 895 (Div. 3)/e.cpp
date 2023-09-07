#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;

	std::vector<int> v(n);
	std::string bits;

	int all_xor = 0;
	std::vector<int> prev(n + 1);

	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
		all_xor ^= v[i];
		prev[i + 1] = (prev[i] ^ v[i]);
	}

	int all_ones = 0;
	std::cin >> bits;
	for (int i = 0; i < n; ++i) {
		if (bits[i] == '1') {
			all_ones ^= v[i];
		}
	}

	int nq;
	std::cin >> nq;
	while (nq--) {
		int ins;
		std::cin >> ins;
		switch (ins) {
			case 1: {
				int l, r;
				std::cin >> l >> r;
				all_ones ^= (prev[r] ^ prev[l - 1]);
				break;
			}
			case 2: {
				int g;
				std::cin >> g;
				if (g == 0) {
					std::cout << (all_ones ^ all_xor) << ' ';
				} else {
					std::cout << all_ones << ' ';
				}
				break;
			}
		}
	}
	std::cout << '\n';
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
