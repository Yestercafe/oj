#include <bits/stdc++.h>
using i64 = long long;

int abs(int a) {
	return a < 0 ? -a : a;
}

void sol() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	std::sort(arr.begin(), arr.end());
	if (arr[0] < 0) {
		std::cout << arr[0] << std::endl;
		return;
	}
	std::cout << arr.back() << std::endl;
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
