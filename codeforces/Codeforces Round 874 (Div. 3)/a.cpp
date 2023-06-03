#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	std::set<std::string> s;
	int n;
	std::cin >> n;
	std::string t;
	std::cin >> t;
	int l = t.length();
	for (int i = 0; i < l - 1; ++i) {
		s.insert(t.substr(i, 2));
	}

	std::cout << s.size() << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		::sol();
	}
}
