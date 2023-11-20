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

const bool __SINGLETON = false;
void solve() {
    int n;
    std::cin >> n;
    std::unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        ++m[a - i];
    }
    i64 ans = 0;
    for (auto& [_, cnt] : m) {
        ans += (cnt - 1) * i64(cnt) / 2;
    }
    std::cout << ans << std::endl;
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
