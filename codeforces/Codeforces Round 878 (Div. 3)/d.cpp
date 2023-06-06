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
		std::set<i64> s;
		for (int i = 0; i < n; ++i) {
			i64 a;
			std::cin >> a;
			s.insert(a);
		}

		std::vector<i64> arr(s.begin(), s.end());
		n = arr.size();
		if (n <= 3) {
			std::cout << 0 << std::endl;
			continue;
		}
		std::sort(arr.begin(), arr.end());

		auto chk = [&](i64 m) {
			i64 tl = arr.front() + 2 * m;
			i64 tr = arr.back() - 2 * m;
			auto d = std::ranges::upper_bound(arr, tl);
			auto u = std::ranges::lower_bound(arr, tr);
			if (d == std::end(arr) || u == std::begin(arr)) {
				return true;
			}
			auto diff = *(u - 1) - *d;
			if (diff < 0 || std::ceil(diff / 2.) <= m) {
				return true;
			} else {
				return false;
			}
		};

		i64 l = -1, r = arr.back() - arr.front() + 1;
		while (l + 1 < r) {
			auto m = l + r >> 1;
			if (chk(m)) {
				r = m;
			} else {
				l = m;
			}
		}

		std::cout << r << std::endl;
	}

	return 0;
}