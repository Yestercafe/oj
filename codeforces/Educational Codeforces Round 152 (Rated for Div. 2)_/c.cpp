#include <bits/stdc++.h>
using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--) {
		int n, m;
		std::cin >> n >> m;
		std::string bs;
		std::cin >> bs;
		std::vector<int> rn0(n), ln1(n);

		for (int i = n - 1, k = -1; i >= 0; --i) {
			if (bs[i] == '0') {
				if (k < 0) {
					rn0[i] = i;
					k = i;
				} else {
					rn0[i] = k;
				}
			} else {
				rn0[i] = i;
				k = i;
			}
		}

		for (int i = 0, k = -1; i < n; ++i) {
			if (bs[i] == '1') {
				if (k < 0) {
					ln1[i] = i;
					k = i;
				} else {
					ln1[i] = k;
				}
			} else {
				ln1[i] = i;
				k = i;
			}
		}
		
		std::set<std::pair<int, int>> s;
		for (int i = 0; i < m; ++i) {
			int l, r;
			std::cin >> l >> r;
			l = rn0[l - 1], r = ln1[r - 1]; 
			if (l >= r) {
				l = r = 0;
			}
			s.emplace(l, r);
		}
		std::cout << s.size() << std::endl;
	}

	return 0;
}
