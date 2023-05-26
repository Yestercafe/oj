#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::string str;
	std::cin >> n >> str;

	int max = -1;
	char prev = 0;
	int acc = 0;
	for (char c : str) {
		if (c == prev) {
			++acc;
		} else {
			prev = c;
			max = std::max(max, acc);
			acc = 1;
		}
	}
	max = std::max(max, acc);

	std::cout << max + 1 << std::endl;
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
