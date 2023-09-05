#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 M = 998244353;

i64 mplus(i64 a, i64 b) {
	return (a % M + b % M) % M;
}

i64 mtimes(i64 a, i64 b) {
	return i64(1.L * (a % M) * (b % M)) % M;
}

i64 power(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b /= 2, a = mtimes(a, a)) {
        if (b % 2) {
            res = mtimes(res, a);
        }
    }
    return res;
}

std::vector<i64> fac;

i64 inv(i64 a) {
	return power(a, M - 2);
}

i64 mcomb(i64 n, i64 r) {
	if (r > n / 2) r = n - r;
	return mtimes(n, inv(mtimes(fac[r], fac[n - r])));
}

i64 sol(int n, int k) {
	// #empty set: main:n - n
	if (n == 0) {
		// all empty set
		return 1;
	}

	// select which ones in S_i => select those + 1 in S_{i+1} forcedly

	std::vector<int> f(k);
	i64 r = k - n + 1;
	for (int i = 1; i <= r; ++i) {
		f[i] = mcomb(r, i);
	}

	for (int e = 1; e <= n; ++e) {
		r = k - n + 1 + e;
		std::vector<int> nf(k);
		for (int pi = 1; pi <= r - 1; ++pi) {
			
		}
	}

	i64 ans1 = power(2, r1);
	// comb(r1, 2) => r2 = r1 - 2 => comb(r2, 0 ~ r2) => r2!
	// comb(r1, 3) => r2 = r1 - 3 => comb(r2, 0 ~ r2) => r2!
	// =>
	// comb(r1, i) * (r1 - i)!
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	fac = std::vector(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = mtimes(fac[i - 1], i);
	}

	std::cout << sol(std::min(n, k), k) << std::endl;

	return 0;
}
