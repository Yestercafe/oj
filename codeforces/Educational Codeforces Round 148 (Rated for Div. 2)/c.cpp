#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	arr.erase(std::unique(arr.begin(), arr.end()), std::end(arr));
	if (arr.size() == 1) {
		std::cout << 1 << std::endl;
		return;
	}
	bool acd = (arr[1] > arr[0]);

	n = arr.size();
	std::vector<bool> acs(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		acs[i] = (arr[i] < arr[i + 1]);
	}

	std::cout << std::unique(acs.begin(), acs.end()) - acs.begin() + 1 << std::endl;
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
