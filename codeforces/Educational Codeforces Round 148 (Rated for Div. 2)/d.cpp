#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 n, q;
	std::cin >> n >> q;
	std::vector<i64> v(n);
	for (i64 i = 0; i < n; ++i)
		std::cin >> v[i];
	std::sort(v.begin(), v.end());

	std::vector<i64> v2(n);

	i64 min_even = 0, min_odd = 0;
	i64 sum_even = 0, sum_odd = 0;
	for (i64 qs = n; qs <= n + 1; ++qs) {
		i64 minus, min = INT64_MAX;
		i64 sum = 0;
		if ((qs - n) % 2 == 0) {
			minus = (qs - n) / 2;
			for (i64 i = 0, iqs = qs; i < n; ++i, --iqs) {
				v2[i] = v[i] + iqs;
				min = std::min(min, v2[i]);
				sum += 1LL * v2[i];
			}
			min_even = min;
			sum_even = sum;
		} else {
			minus = (qs - n) / 2 + 1;
			for (i64 i = 0, iqs = qs; i < n - 1; ++i, --iqs) {
				v2[i] = v[i] + (i != n - 1 ? iqs : 0);
				min = std::min(min, v2[i]);
				sum += 1LL * v2[i];
			}
			min_odd = min;
			sum_odd = sum + v.back();
		}
	}
	
	while (q--) {
		i64 qs;
		std::cin >> qs;
		i64 min = INT64_MAX;
		if (qs <= n) {
			for (i64 i = 0, iqs = qs; i < n; ++i, --iqs) {
				v2[i] = v[i] + (iqs < 0 ? 0 : iqs);
				min = std::min(min, v2[i]);
			}
		} else {
			i64 minus;
			i64 sum = 0;
			if ((qs - n) % 2 == 0) {
				minus = (qs - n) / 2;
				min = min_even + (qs - n);
				sum = sum_even + 1LL * n * (qs - n);
			} else {
				minus = (qs - n) / 2 + 1;
				min = min_odd + (qs - n - 1);
				sum = sum_odd + 1LL * (n - 1) * (qs - n - 1);
				min = std::min(min, v.back());
			}

			sum -= 1LL * n * min;
			if (minus <= sum) {
				;
			} else {
				min = min - (minus - sum + n - 1) / n;
			}
		}
		std::cout << min << " \n"[q == 0];
	}

	return 0;
}

/*
8 5 4 2

1 2 3            5
1 2 3 4          6
-1 3 4 5         7
2 4 5 6          8
-2 5 6 7         8
3 6 7 8          10
-3 7 8 9         
4 8 9 10


-1 3 4 5 6
1 2 3 4 5 6 7   ceil((7-4)/2) = 2



-5000 10000 10001 10002

*/