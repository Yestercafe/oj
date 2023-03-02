#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050
#define K 3

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s, t;
    std::cin >> s >> t;
    if (n == k + 1) {
        bool yes = (s == t);
        std::swap(s.front(), s.back());
        yes |= (s == t);
        std::cout << (yes ? "YES" : "NO") << std::endl;
        return ;
    }

    if (n <= k) {
        std::cout << (s == t ? "YES" : "NO") << std::endl;
        return ;
    }
    if (2 * k > n) {
        string ss = s.substr(n - k, 2 * k - n);
        string st = t.substr(n - k, 2 * k - n);
        if (ss != st) {
            std::cout << "NO" << std::endl;
            return ;
        }
    }
    int cnt[26] {};
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < n; ++i) {
        cnt[t[i] - 'a']--;
        if (cnt[t[i] - 'a'] < 0) {
            std::cout << "NO" << std::endl;
            return ;
        }
    }
    std::cout << "YES" << std::endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        ::solve();
    }
    return 0;
}
