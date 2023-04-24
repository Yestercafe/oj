#include <bits/stdc++.h>
using i64 = long long;

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		i64 n;
		std::cin >> n;
		
		std::cout << n * n + 10LL + 2 * (n - 4) << std::endl;
	}
	return 0;
}
