#include <bits/stdc++.h>
using i64 = long long;

void sol() {
	int n, m;
	std::cin >> n >> m;
	std::vector mat(n * m , 0);
	int p = 1;
	bool inc = true;
	bool rev = (n * m - 1) % 4;
	for (int i = 0; i < n * m; ++i) {
		mat[i] = p;
		if (inc) {
			if (p + 4 <= n * m) {
				p += 4;
			} else {
				inc = false;
				if (rev) {
					++p;
				} else {
					--p;
				}
			}
		} else {
			if (p - 4 >= 1) {
				p -= 4;
			} else {
				inc = true;
				if (rev) {
					++p;
				} else {
					--p;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; ++j) {
				std::cout << mat[i * m + j] << " \n"[j == m - 1];
			}
		} else {
			for (int j = m - 1; j >= 0; --j) {
				std::cout << mat[i * m + j] << " \n"[j == 0];
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int tt;
	std::cin >> tt;
	for (int i = 0; i < tt; ++i) {
		if (i != 0) std::cout << '\n';
		::sol();
	}
	return 0;
}
