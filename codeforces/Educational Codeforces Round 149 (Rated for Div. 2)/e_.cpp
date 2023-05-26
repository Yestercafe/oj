#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int k;
	std::cin >> k;

	int n = (1 << k);
	std::vector<int> arr(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	// 1
	// 2 3
	// 5 6 7 8
	

	return 0;
}
