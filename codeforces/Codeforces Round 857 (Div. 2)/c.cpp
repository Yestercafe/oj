#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define N 300050
// #define ONLINE_JUDGE
// Copy to use:
#ifndef ONLINE_JUDGE
#endif /* ONLINE_JUDGE */

i64 compose(i64 i, i64 j) {
    i64 ans = 0;
    // std::cout << "start:" << i << ' ' << j << ' ' << std::endl;
    int pos = 0;
    while (i != 0 || j != 0) {
        ans |= (((i & 1) << (pos * 2))| ((j & 1) << (pos * 2 + 1)));
        i >>= 1;
        j >>= 1;
        ++pos;
    }
    // std::cout << ans << std::endl;
    return ans;
}

const bool __SINGLETON = false;
void solve() {
    i64 n, m;
    std::cin >> n >> m;
    std::cout << n * m << std::endl;
    std::vector v(n, std::vector(m, 0LL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << (v[i][j] = compose(i, j)) << " \n"[j == m - 1];
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
