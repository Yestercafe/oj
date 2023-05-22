#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	std::vector<std::vector<int>> mat(n, std::vector<int>(n));
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int a;
			std::cin >> a;
			mat[i][j] = mat[j][i] = a;
		}
	}

	for (auto& v : mat) {
		for (auto a : v) {
			std::cout << a << ' ';
		}
		std::cout << std::endl;
	}

	std::vector<std::vector<int>> p(n, std::vector<int>(n + 1));
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			p[k][i + 1] = p[k][i] + mat[k][i];
		}
	}

	std::vector<int> s(n);
	for (int i = 0; i < n; ++i) {
		s[i] = p[i][n] - p[i][i];
	}

	std::sort(s.begin(), s.end(), std::greater<>{});
	for (auto a : s) {
		std::cout << a << ' ';
	}
	endl(std::cout);

	std::cout << std::accumulate(s.begin(), s.begin() + k, 0) << std::endl;

	return 0;
}
