#include <bits/stdc++.h>
using i64 = long long;

struct S {
	int v;
	int m, M;
};

void sol() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::vector<std::vector<S>> f(n, std::vector<S>(n, {0, 0, 0}));
	for (int i = 0; i < n; ++i) {
		f[i][i].m = f[i][i].M = a[i];
	}

	i64 ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] < a[i + 1]) {
			f[i][i + 1].m = a[i];
			f[i][i + 1].M = a[i + 1];
		} else {
			f[i][i + 1].v = 1;
			++ans;
			f[i][i + 1].m = a[i + 1];
			f[i][i + 1].M = a[i];
		}
	}
	
	for (int d = 2; d < n; ++d) {          // 5 * 10^3
		for (int i = 0; i < n - d; ++i) {      // 5 * 10^3
			f[i][i + d].m = std::min(f[i][i + d - 1].m, a[i + d]);
			f[i][i + d].M = std::max(f[i][i + d - 1].M, a[i + d]);
			f[i][i + d].v = d;
			// head
			int head_v = a[i];
			if (head_v < f[i + 1][i + d].m) {
				f[i][i + d].v = std::min(f[i][i + d].v, f[i + 1][i + d].v);
			}
			// mid
			for (int mid = i + 1; mid < i + d; ++mid) {    // 5 * 10^3
				int mid_v = a[mid];
				if (f[i][mid - 1].M < mid_v && mid_v < f[mid + 1][i + d].m) {
					f[i][i + d].v = std::min(f[i][i + d].v, f[i][mid - 1].v + f[mid + 1][i + d].v);
				}
			}
			// tail
			int tail_v = a[i + d];
			if (f[i][i + d - 1].M < tail_v) {
				f[i][i + d].v = std::min(f[i][i + d].v, f[i][i + d - 1].v);
			}

			ans += 1LL * f[i][i + d].v;
		}
	}
	std::cout << ans << std::endl;
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
