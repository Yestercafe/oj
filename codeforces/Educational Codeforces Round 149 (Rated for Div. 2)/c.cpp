#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	std::string s;
	std::cin >> s;
	s = std::string("0") + s + std::string("1");

	int n = s.length();

	for (int i = 1; i < n - 1; ++i) {
		if (s[i] == '?')
			s[i] = s[i - 1];
	}

	for (int i = 1; i < n - 1; ++i) {
		std::cout << s[i];
	}
	std::cout << std::endl;
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
