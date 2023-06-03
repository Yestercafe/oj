#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n;
	std::cin >> n;
	std::map<int, std::vector<int>> s;
	for (int i = 0; i < n; ++i) {
		int a, b;
		std::cin >> a >> b;
		s[a].push_back(b);
	}
	std::vector<std::pair<int, std::vector<int>>> vp;
	for (auto& [a, v] : s) {
		std::ranges::sort(v, std::greater<>{});
		vp.push_back({a, std::move(v)});
	}

	int used = 0;
	i64 ans = 0;
	std::map<int, int> boom;
	for (auto& [a, v] : vp) {
		int upper = v.size();
		int i = 0;
		for (i = 0; i < upper; ++i) {
			if (used == a) break;
			if (int& u = boom[used]) {
				used -= u;
				u = 0;
			}
			ans += v[i];
			++used;
			++boom[a];
		}
	}

	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) ::sol();
	return 0;
}
