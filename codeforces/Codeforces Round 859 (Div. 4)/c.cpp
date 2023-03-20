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
    std::string s;
    std::cin >> s;
    std::unordered_map<char, int> m;
    int exact = 1;
    for (int i = 0; i < n; ++i) {
        char ch = s[i];
        auto fnd = m.find(ch);
        if (fnd != m.end()) {
            if (fnd->second != exact) {
                std::cout << "NO" << std::endl;
                return ;
            }
        } else {
            m[ch] = exact;
        }
        exact = 1 - exact;
    }
    std::cout << "YES" << std::endl;
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
