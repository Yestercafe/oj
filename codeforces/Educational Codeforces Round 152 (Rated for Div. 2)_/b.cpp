#include <bits/stdc++.h>
using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--) {
		int n, d;
		std::cin >> n >> d;
		std::vector<std::pair<int, int>> a(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i].first;
			a[i].first %= d;
			if (a[i].first == 0) a[i].first = d;
			a[i].first = -a[i].first;
			a[i].second = i;
		}

		std::sort(a.begin(), a.end());

		for (auto [_, idx] : a)
			std::cout << idx + 1 << ' ';

		std::cout << std::endl;
	}

	return 0;
}
