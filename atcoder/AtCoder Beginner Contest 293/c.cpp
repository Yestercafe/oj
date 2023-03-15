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

const bool __SINGLETON = true;
void solve() {
    int h, w;
    std::cin >> h >> w;
    std::vector v(h, std::vector(w, 0));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cin >> v[i][j];
        }
    }
    std::unordered_set<int> s;
    function<i64(int, int)> dfs = [&](int i, int j) -> i64 {
        if (s.find(v[i][j]) != s.end()) return 0;
        s.insert(v[i][j]);
        if (i == h - 1 && j == w - 1) {
            s.erase(v[i][j]);
            return 1;
        }
        i64 ans = 0;
        if (i + 1 < h) ans += dfs(i + 1, j);
        if (j + 1 < w) ans += dfs(i, j + 1);
        s.erase(v[i][j]);
        return ans;
    };
    std::cout << dfs(0, 0) << std::endl;
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
