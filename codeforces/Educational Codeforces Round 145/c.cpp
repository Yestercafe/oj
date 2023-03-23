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
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> v(n, 2LL);
    k = n * (n + 1) / 2 - k;

    int d = n;
    while (k != 0) {
        if (k >= d) {
            v[d - 1] = -2 * d + 1;
            k -= d;
        } else {
            v[d - 1] = -2 * k + 1;
            k = 0;
        }
        --d;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " \n"[i == n - 1];
    }

    // std::vector<i64> pref(n + 1);
    // std::partial_sum(v.begin(), v.end(), pref.begin() + 1);
    // i64 stat = 0;
    // for (int l = 1; l < n + 1; ++l) {
    //     for (int r = l; r < n + 1; ++r) {
    //         if (pref[r] - pref[l - 1] > 0) {
    //             ++stat;
    //         }
    //     }
    // }
    // std::cout << "stat = " << stat << std::endl;
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
