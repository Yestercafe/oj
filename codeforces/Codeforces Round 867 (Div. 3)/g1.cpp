#include <bits/stdc++.h>
using i64 = long long;

bool neq3(char a, char b, char c) {
	return a != b && b != c && a != c;
}

i64 pn3(i64 n) {
	return n * (n - 1) * (n - 2);
}

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::map<i64, i64> cnt;

		i64 ma = 0;
		for (int i = 0; i < n; ++i) {
			i64 a;
			std::cin >> a;
			ma = std::max(ma, a);
			++cnt[a];
		}

		i64 ans = 0;
		for (auto [a, c] : cnt) {
			if (c >= 3) {
				ans += pn3(c);
			}

			for (i64 b = 2; a * b <= ma / b; ++b) {
				if (cnt.contains(a * b) && cnt.contains(a * b * b)) {
					ans += c * cnt[a * b] * cnt[a * b * b];
				}
			}
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
