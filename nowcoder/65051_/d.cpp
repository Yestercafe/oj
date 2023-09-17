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

    int n;
    std::cin >> n;
    std::vector<i64> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    i64 ans = 0;
    for (int b = 0; b < 31; ++b) {
        int ones = 0, zeros = 0;
        for (int i = 1; i < n; ++i) {
            if ((v[i - 1] >> b) & 1) {
                ones += i;
            } else {
                zeros += i;
            }
            int cnt;
            if ((v[i] >> b) & 1) {
                cnt = zeros;
            } else {
                cnt = ones;
            }
            ans = mp(ans, mm(n - i, mm(cnt, 1 << b)));
        }
    }

    std::cout << ans << std::endl;
    
    return 0;
}
