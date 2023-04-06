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

i64 sol(i64 x) {
    i64 fx = 0;
    i64 srx = static_cast<i64>(std::sqrt(x));
    if (srx * srx == x) {
        fx = srx;
    } else {
        i64 f1 = srx;
        i64 f2 = srx + 1;
        if (f2 > x) return f1;
        if (f1 + x - x / f1 * f1 < f2 + x - x / f2 * f2) {
            fx = f1;
        } else {
            fx = f2;
        }
    }

    return fx;
}

const bool __SINGLETON = false;
void __solve() {
    i64 x, y;
    std::cin >> x >> y;
    if (x > y) std::swap(x, y);
    // y >= x

    i64 min_ans = INT64_MAX, min_s = 0;
    for (int s = 1; s <= 4LL * std::sqrt(std::max(x, y)); ++s) {
        i64 ans;
        if (s > x && s > y)  {
            ans = (i64) std::ceil((long double) x / s) + (i64) std::ceil((long double) y / s) + s - 1;
        } else if (s > y) {
            ans = (i64) std::ceil((long double) x / s) + (i64) std::ceil((long double) y / s) + s + x - x / s * s - 1;
        } else if (s > x) {
            ans = (i64) std::ceil((long double) x / s) + (i64) std::ceil((long double) y / s) + s + y - y / s * s - 1;
        }
        else ans = (i64) std::ceil((long double) x / s) + (i64) std::ceil((long double) y / s) + s + std::max(x - x / s * s, y - y / s * s) - 1;
        // std::cout << ans << ' ';
        if (ans < min_ans) {
            min_ans = ans;
            min_s = s;
        }
    }
    std::cout << min_ans << std::endl;
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
