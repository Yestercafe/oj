#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n, k;
	std::cin >> n >> k;
	if ((n - 1) % k == 0) {
		std::cout << (n - 1) / k + 1 << std::endl;
	} else {
		std::cout << (n - 1) / k + 2 << std::endl;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) ::sol();
	return 0;
}
