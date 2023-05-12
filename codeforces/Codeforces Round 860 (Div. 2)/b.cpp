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
    std::unordered_map<int, int> last;
    std::vector<std::vector<int>> mat;
    int t;
    std::cin >> t;
    for (int day = 0; day < t; ++day) {
        int n, a;
        std::cin >> n;
        mat.push_back(std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            std::cin >> mat[day][i];
            last[mat[day][i]] = day;
        }
    }

    std::vector<int> ans(t);
    for (int d = 0; d < t; ++d) {
        bool flag = false;
        for (auto a : mat[d]) {
            if (last[a] == d) {
                ans[d] = a;
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << -1 << std::endl;
            return ;
        }
    }
    for (int i = 0; i < t; ++i) {
        std::cout << ans[i] << " \n"[i == t - 1];
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
