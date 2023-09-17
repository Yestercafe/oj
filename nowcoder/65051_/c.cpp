#include <bits/stdc++.h>
using i64 = long long;
constexpr int M = 1e9 + 7;

i64 mm(i64 a, i64 b) {
    return ((a % M) * (b % M)) % M;
}

i64 mp(i64 a, i64 b) {
    return ((a % M) + (b % M)) % M;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<i64> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());
    i64 ans = v.back();
    for (int i = 1; i <= k; ++i) {
        ans = mm(ans, v[n - 1 - i]);
    }
    ans = mp(ans, k);

    for (int i = 0; i < n - k - 1; ++i) {
        ans = mp(ans, v[i]);
    }

    std::cout << ans << std::endl;
    
    return 0;
}
