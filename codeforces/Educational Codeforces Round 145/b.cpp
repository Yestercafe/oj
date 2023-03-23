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
    i64 n;
    std::cin >> n;

    i64 l = -1, r = std::sqrt(INT64_MAX);
    while (l + 1 < r) {
        auto mid = l + (r - l) / 2;
        if (mid * mid <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (l * l == n) {
        std::cout << l - 1 << std::endl;
    } else {
        std::cout << l << std::endl;
    }
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
