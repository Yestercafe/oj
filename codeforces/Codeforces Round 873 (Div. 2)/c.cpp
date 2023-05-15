#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	for (int i = 0; i < n; ++i)
		std::cin >> b[i];

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	constexpr i64 MOD = 1e9 + 7;
	i64 ans = 1;
	for (int i = 0; i < n && ans > 0; ++i) {
		auto lb = std::lower_bound(b.begin(), b.end(), a[i]);
		if ((lb - b.begin() - i) <= 0) {
			ans = 0;
			break;
		}
		ans = (ans * (lb - b.begin() - i)) % MOD;
	}
	std::cout << (ans > 0 ? ans : 0) << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		::sol();
	}
	return 0;
}
