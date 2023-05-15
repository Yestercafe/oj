#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;
	std::vector<int> s(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> s[i];
	}

	int gcd = s[0] - 1;
	for (int i = 0; i < n && gcd != 1; ++i) {
		int a = s[i] - i - 1;
		if (a < 0) a = -a;
		if (a == 0) continue;
		gcd = std::gcd(gcd, a);
	}

	std::cout << gcd << std::endl;
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
