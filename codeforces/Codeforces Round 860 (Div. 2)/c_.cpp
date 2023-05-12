#include <bits/stdc++.h>
typedef long long i64;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define N 300050
#if 0  // for gcc C++20
namespace ranges = std::ranges;
#endif
// #define ONLINE_JUDGE
// Copy to use:
#ifndef ONLINE_JUDGE
#endif /* ONLINE_JUDGE */

const bool __SINGLETON = false;
void __solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n), b(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
    }

    int ans = n;
    i64 prev = -1, gcd = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (prev < 0) {
            auto lcm = std::lcm(b[i], b[i + 1]);
            if (a[i] * b[i] % lcm == 0 && a[i + 1] * b[i + 1] % lcm == 0) {
                --ans;
                prev = lcm;
                gcd = std::gcd(a[i], a[i + 1]);
            } else {
                prev = -1;
                gcd = -1;
            }
        } else {
            auto lcm = std::lcm(prev, b[i + 1]);
            if (a[i + 1] * b[i + 1] % lcm == 0) {
                --ans;
                prev = lcm;
                gcd = std::gcd(gcd, a[i + 1]);
            } else {
                if (a[i + 1] * b[i + 1] % lcm == 0 && gcd % (lcm / prev) == 0) {
                    --ans;
                    prev = lcm;
                    gcd /= lcm / prev;
                    gcd = std::gcd(gcd, a[i + 1]);
                } else {
                    prev = -1;
                    gcd = -1;
                }
            }
        }
    }
    std::cout << ans << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    if (__SINGLETON) {
        ::__solve();
    } else {
        i64 tt;
        std::cin >> tt;
        while (tt--) ::__solve();
    }
    return 0;
}
