#include <bits/stdc++.h>
using i64 = long long;

bool neq3(char a, char b, char c) {
	return a != b && b != c && a != c;
}

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::string s;
		std::cin >> s;

		if (n % 2 == 1) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::unordered_map<char, int> cnt;
		int tot = 0;
		for (int i = 0; i < n / 2; ++i) {
			if (s[i] == s[n - 1 - i]) {
				++cnt[s[i]];
				++tot;
			}
		}

		if (cnt.empty()) {
			std::cout << 0 << std::endl;
			continue;
		}

		std::vector<std::pair<char, int>> v(cnt.begin(), cnt.end());
		std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
		if (tot % 2 == 0 && v[0].second <= tot / 2) {
			std::cout << tot / 2 << std::endl;
			continue;
		}
		if (tot % 2 == 1 && v[0].second <= tot / 2) {
			if (tot != 1) {  // 3, 5, 7, ...
				std::cout << tot / 2 + 1 << std::endl;
			} else {
				bool flag = false;
				for (int i = 0; i < n / 2; ++i) {
					if (neq3(v[0].first, s[i], s[n - 1 - i])) {
						flag = true;
						break;
					}
				}
				if (flag) std::cout << tot / 2 + 1 << std::endl;
				else std::cout << -1 << std::endl;
			}
			continue;
		}

		int need = v[0].second - (tot - v[0].second);
		int ans = tot - v[0].second;
		for (int i = 0; need > 0 && i < n / 2; ++i) {
			if (neq3(v[0].first, s[i], s[n - 1 - i])) {
				--need;
				++ans;
			}
		}
		if (need == 0) {
			std::cout << ans << std::endl;
		} else {
			std::cout << -1 << std::endl;
		}
	}
	return 0;
}
