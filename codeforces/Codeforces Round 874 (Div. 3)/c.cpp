#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	int min_o = INT_MAX, min_e = INT_MAX;
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
		if (arr[i] & 1) min_o = std::min(min_o, arr[i]);
		else min_e = std::min(min_e, arr[i]);
	}

	bool ans = true;
	for (int i = 0; i < n; ++i) {     // to generate odds
		if (arr[i] & 1) {
			if (arr[i] > 0) continue;
			if (arr[i] - min_e <= 0) {
				ans = false;
				break;
			}
		} else {
			if (arr[i] - min_o <= 0) {
				ans = false;
				break;
			}
		}
	}
	if (ans) {
		std::cout << "YES" << std::endl;
		return;
	}

	ans = true;
	for (int i = 0; i < n; ++i) {     // evens
		if (arr[i] & 1) {
			if (arr[i] - min_o <= 0) {
				ans = false;
				break;
			}
		} else {
			if (arr[i] > 0) continue;
			if (arr[i] - min_e <= 0) {
				ans = false;
				break;
			}
		}
	}

	std::cout << (ans ? "YES" : "NO") << std::endl;
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
