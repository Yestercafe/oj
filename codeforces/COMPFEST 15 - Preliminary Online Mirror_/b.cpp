#include <bits/stdc++.h>
using i64 = long long;
constexpr int M = 998244353;

i64 power(i64 a, i64 b, i64 p) {
    auto res = 1;
    for (; b; b /= 2, a = a * a % p) {
        if (b % 2) {
            res = res * a % p;
        }
    }
    return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, a;
	std::cin >> n;
	std::map<int, int> facts;
	std::vector<int> as(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		as[i] = a;
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		facts.emplace(as[i], a);
	}

	int ans = 0;
	int m;
	std::cin >> m;
	std::vector<int> cs(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> a;
		if (ans >= 0) {
			cs[i] = a;
			if (!facts.count(a)) {
				ans = -1;
			}
		}
	}

	if (ans >= 0) ans = facts.size();
	for (int i = 0; i < m; ++i) {
		std::cin >> a;
		if (ans >= 0) {
			auto other = facts[cs[i]];
			if (a == other) {
				--ans;
			} else if (a > other) {
				ans = -1;
			}
		}
	}

	if (ans < 0) {
		std::cout << 0 << '\n';
	} else if (ans == 0) {
		std::cout << 1 << '\n';
	} else {
		std::cout << power(2, ans, M) << '\n';
	}

	return 0;
}
