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
    int n;
    std::cin >> n;
    i64 te = 0, to = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        if (a & 1) {
            to += a;
        } else {
            te += a;
        }
    }
    if (te > to) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
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
