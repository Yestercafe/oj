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
    std::string str;
    std::cin >> str;
    std::unordered_map<char, int> cnt;
    for (char ch : str) {
        ++cnt[ch];
    }
    if (cnt.size() == 4 || cnt.size() == 3) {
        std::cout << 4 << std::endl;
    }
    else if (cnt.size() == 2) {
        auto f = *cnt.begin();
        auto s = *(++cnt.begin());
        if (f.second == 2 && s.second == 2) {
            std::cout << 4 << std::endl;
        } else {
            std::cout << 6 << std::endl;
        }
    } else {
        std::cout << -1 << std::endl;
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
