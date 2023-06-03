#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n, k;
	std::cin >> n >> k;
	std::vector<std::pair<int, int>> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i].first;
		b[i].second = i;
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	std::vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[a[i].second] = b[i].first;
	}
	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		::sol();
	}
}
