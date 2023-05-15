#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int ii = i + 1;
		arr[i] = ii;
		sum += ii;
	}

	arr[0] += (sum + n - 1) / n * n - sum;

	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " \n"[i == n - 1];
	}
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
