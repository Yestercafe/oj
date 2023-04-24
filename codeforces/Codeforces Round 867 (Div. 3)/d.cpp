#include <bits/stdc++.h>
using i64 = long long;

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		i64 n;
		std::cin >> n;
		
		if (n == 1) {
			std::cout << 1 << std::endl;
			continue;
		}

		if (n % 2 == 1) {
			std::cout << -1 << std::endl;
			continue;
		}

		int a = n, sum = 0;
		int left = 1, right = n - 1;
		bool is_left = true;
		for (int i = 0; i < n; ++i) {
			sum = (sum + a) % n;
			std::cout << a << " \n"[i == n - 1];
			if (is_left) {
				a = right - sum;
				--right;
			} else {
				a = left + n - sum;
				++left;
			}
			is_left = !is_left;
		}
	}
	return 0;
}
