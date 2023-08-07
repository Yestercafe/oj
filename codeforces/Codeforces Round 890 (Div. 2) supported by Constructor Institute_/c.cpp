#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> arr(n + 1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
		ans = std::max(ans, arr[i]);
	}
	arr.back() = -8e8;

	for (int i = 0; i < n - 1; ++i) {
		int left = ans - 1, right = 1e8 + 2001;
		auto chk = [n, k, i, &arr](int m) {
			int mk = k, mi = i;
			if (arr[mi] >= m) return true;
			if (mk < m - arr[mi]) return false;
			mk -= m - arr[mi];
			int curr_arr_i = m;
			while (mi + 1 < n + 1 && curr_arr_i - 1 > arr[mi + 1]) {
				// curr_arr_i - 1 > arr[i + 1] means arr[i + 1] can't support the large enough arr[i] to
				// satisfy arr[i] <= arr[i + 1], s.t. ++arr[i] => arr[i] + 1 < arr[i + 1].
				mk -= curr_arr_i - 1 - arr[mi + 1];
				--curr_arr_i;
				++mi;
				if (mk < 0) return false;
			}
			return true;
		};
		while (left + 1 < right) {
			auto mid = left + right >> 1;
			if (chk(mid)) {
				left = mid;
			} else {
				right = mid;
			}
		}

		ans = std::max(ans, right - 1);
	}

	std::cout << ans << std::endl;
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
