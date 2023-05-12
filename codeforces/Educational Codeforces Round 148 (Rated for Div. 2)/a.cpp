#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	std::string s;
	std::cin >> s;
	std::map<char, int> cnt;
	for (auto ch : s)
		++cnt[ch];

	int odd_cnt = 0;
	for (auto [_, c] : cnt) {
		if (c % 2 == 1)
			++odd_cnt;
	}

	if (odd_cnt > 1 || cnt.size() == 1) {
		std::cout << "NO" << std::endl;
		return;
	}
	if (cnt.size() == 2) {
		std::vector<int> vc;
		for (auto [_, c] : cnt) {
			vc.push_back(c);
		}
		std::sort(vc.begin(), vc.end());
		if (vc[0] == 1) {
			std::cout << "NO" << std::endl;
			return;
		}
	}
	std::cout << "YES" << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int tt;
	std::cin >> tt;
	while (tt--) {
		::sol();
	}
	return 0;
}
