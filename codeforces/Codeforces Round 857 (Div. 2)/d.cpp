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
namespace ranges = std::ranges;

const bool __SINGLETON = false;
void solve() {
    i64 n;
    std::cin >> n;
    std::vector<i64> vs(n);
    i64 tot1 = 0, tot2 = 0;
    for (int i = 0; i < n; ++i) {
        i64 a, b;
        std::cin >> a >> b;
        vs[i] = a + b;
        tot1 += a;
        tot2 += b;
    }
    auto tot = std::min(tot1, tot2);

    i64 min = std::numeric_limit<i64>::max();
    std::unordered_set<i64> s;
    function<void(int, i64)> dfs = [&](int i, i64 csum) {
        if (csum >= tot) {
            min = std::min(std::abs(csum - tot), min);
            return ;
        }
        if (i == n) return ;
        auto c = vs[i];
        for (auto a : s) {
            
        }
    };
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
