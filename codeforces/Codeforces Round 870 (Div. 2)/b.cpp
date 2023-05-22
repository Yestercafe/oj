#include <bits/stdc++.h>
using i64 = long long;

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::vector<i64> arr(n);
		i64 max_elem = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> arr[i];
			max_elem = std::max(max_elem, arr[i]);
		}

		std::set<i64, std::greater<i64>> s;
		bool isPal = true;
		for (int i = 0; i < n / 2; ++i) {
			if (arr[i] == arr[n - 1 - i]) {
				continue;
			}
			if (arr[i] > arr[n - 1 - i]) {
				std::swap(arr[i], arr[n - 1 - i]);
			}
			int diff = arr[n - 1 - i] - arr[i];
			if (s.empty()) {
				i64 sr = std::sqrt(static_cast<long double>(diff));
				for (int f = 1; f <= sr + 1; ++f) {
					if (diff % f == 0) {
						s.insert(diff / f);
						s.insert(f);
					}
				}
			} else {
				std::vector<i64> del;
				for (auto f : s) {
					if (diff % f != 0) {
						del.push_back(f);
					}
				}
				for (auto de : del) {
					s.erase(de);
				}
				if (s.empty()) {
					isPal = false;
					break;
				}
			}
		}

		if (isPal && s.empty()) {
			std::cout << 0 << std::endl;
		} else if (isPal) {
			std::cout << *(s.begin()) << std::endl;
		} else {
			std::cout << -1 << std::endl;
		}
	}
	return 0;
}
