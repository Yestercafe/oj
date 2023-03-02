#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define N 300050
#if 1 // for C++20
namespace ranges = std::ranges;
#endif
// #define ONLINE_JUDGE
// Copy to use:
#ifndef ONLINE_JUDGE
#endif /* ONLINE_JUDGE */

const bool __SINGLETON = true;
void solve() {
    int n;
    std::cin >> n;
    std::unordered_set<int> ds;
    int min_d = INT_MAX, max_d = INT_MIN;
    int prev, curr;
    for (int i = 0; i < n; ++i) {
        prev = curr;
        std::cin >> curr;
        if (i == 0) continue;
        int d = std::abs(curr - prev);
        if (ds.contains(d)) {
            std::cout << "Not jolly" << std::endl;
            return ;
        }
        ds.insert(d);
        max_d = std::max(max_d, d);
        min_d = std::min(min_d, d);
    }

    if (max_d - min_d != n - 2 || ds.size() != n - 1) {
        std::cout << "Not jolly" << std::endl;
    } else {
        std::cout << "Jolly" << std::endl;
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
