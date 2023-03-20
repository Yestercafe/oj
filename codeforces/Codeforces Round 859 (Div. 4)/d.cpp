#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define N 300050
#if 0  // for C++20
namespace ranges = std::ranges;
#endif
// #define ONLINE_JUDGE
// Copy to use:
#ifndef ONLINE_JUDGE
#endif /* ONLINE_JUDGE */


const bool __SINGLETON = false;
void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> v(n);
    int cnt_odd = 0;
    std::vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        if (v[i] & 1) ++cnt_odd;
        pref[i + 1] = cnt_odd;
    }
    while (q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        --l, --r;
        int dn = r - l + 1;
        if (k % 2) {  // odd
            if ((cnt_odd + (dn - pref[r + 1] - pref[l])) % 2) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        } else {   // even
            if ((cnt_odd - (pref[r + 1] - pref[l])) % 2) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (__SINGLETON) {
        ::solve();
    } else {
        i64 tt;
        cin >> tt;
        while (tt--) ::solve();
    }
    return 0;
}
