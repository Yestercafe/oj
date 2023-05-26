#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	if (n == 1) {
		std::cout << 1 << std::endl;
		return;
	}

	int r = 0;
	if (arr[0] == n) {
		for (int i = 0; i < n; ++i) {
			if (arr[i] == n - 1) {
				r = i;
				break;
			}
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if (arr[i] == n) {
				r = i;
				break;
			}
		}
	}

	assert(r > 0);

	if (r + 1 == n) {
		if (arr[r - 1] < arr[0]) {
			std::cout << arr.back();
			for (int i = 0; i < n - 1; ++i) {
				std::cout << ' ' << arr[i];
			}
			std::cout << std::endl;
			return;
		}
	}

	int p = arr[r - 1];
	int l;
	for (l = r - 2; l >= 0; --l) {
		if (arr[l] < arr[0]) {
			break;
		}
	}

	std::cout << arr[r];
	for (int i = r + 1; i < n; ++i) {
		std::cout << ' ' << arr[i];
	}
	for (int i = r - 1; i > l; --i) {
		std::cout << ' ' << arr[i];
	}
	for (int i = 0; i <= l; ++i) {
		std::cout << ' ' << arr[i];
	}
	std::cout << std::endl;
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
