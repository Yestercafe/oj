#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> arr(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i].first >> arr[i].second;
	}

	std::sort(arr.begin(), arr.end());

	int rec = 0;
	int min = INT_MAX;
	int i = 0;

	for (rec = 1; rec <= 500; ++rec) {
		while (i < n && arr[i].first == rec) {
			auto [d, s] = arr[i++];
			min = std::min(min, 2 * d + s - 2);
		}
		
		if (2 * rec >= min) {
			break;
		}
	}

	std::cout << rec << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--) {
		sol();
	}

	return 0;
}
