#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> arr(n);
	i64 sum = 0LL;
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
		sum += 1LL * arr[i];
	}
	std::sort(arr.begin(), arr.end(), std::greater<>{});

	i64 pf = 0, sf = 0;
	for (int i = 0; i < k; ++i) {
		pf += 1LL * arr[i];
	}
	auto min = pf;
	for (int i = 0; i < k; ++i) {
		pf -= 1LL * arr[k - 1 - i];
		sf += 1LL * arr[n - 1 - i * 2] + arr[n - 1 - i * 2 - 1];
		min = std::min(min, pf + sf);
	}
	std::cout << sum - min << std::endl;
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
