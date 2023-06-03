#include <bits/stdc++.h>
using i64 = long long;
using ll = i64;

constexpr int p = 1e9 + 7;

ll powmod(ll a, ll b) {
	if (b == -1) {
		b = p - 2;
	}
    ll ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

ll mulmod(ll a, ll b) {
	return (a % p) * (b % p) % p;
}

ll addmod(ll a, ll b) {
	return ((a % p) + (b % p)) % p;
}

void sol() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];
	std::sort(arr.begin(), arr.end());
	std::map<int, int> cnts;
	for (auto a : arr)
		++cnts[a];
	arr.erase(std::unique(arr.begin(), arr.end()), arr.end());

	std::map<int, int> fact;
	for (i64 i = 1, f = 1; i <= n; ++i) {
		f = mulmod(f, i);
		fact[i] = f;
	}

	std::vector<i64> pm(n + 1), ps(n + 1);
	for (int i = 0; i < n; ++i) {
		pm[i + 1] = addmod(pm[i], fact[arr[i]]);
		ps[i + 1] = addmod(ps[i], arr[i]);
	}

	n = arr.size();
	i64 ans = 0;
	for (int i = 0; i < n; ++i) {
		auto pos = std::upper_bound(arr.begin(), arr.end(), arr[i] + m);
		if ((ps[pos - arr.begin()] + p - ps[i]) < m) break;
		ans = addmod(ans, mulmod(mulmod(fact[(ps[pos - arr.begin()] + p - ps[i]) % p], powmod(fact[m], -1)), (pm[pos - arr.begin()] + p - pm[i]) % p));
	}

	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		::sol();
	}
}
