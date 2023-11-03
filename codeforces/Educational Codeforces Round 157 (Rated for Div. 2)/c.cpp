#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n;
    std::cin >> n;
    std::map<int, std::map<int, i64>> d;
    std::vector<std::string> t(n);
    std::map<int, std::map<int, i64>> p;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        auto pref = 0, suff = 0;
        for (auto ch : s) {
            suff += (ch - '0');
        }
        int ss = s.size();
        ++p[ss][suff];
        ++d[0 - ss][pref - suff];
        for (int j = 0; j < s.size(); ++j) {
            suff -= s[j] - '0';
            pref += s[j] - '0';
            ++d[j + 1 - (ss - j - 1)][pref - suff];
        }

        t[i] = std::move(s);
    }

    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        auto pref = 0, suff = 0;
        for (auto ch : t[i]) {
            pref += ch - '0';
        }

        int len = t[i].size();
        ans += d[-len][-pref];

        for (int j = len - 1; j > len - j; --j) {
            pref -= t[i][j] - '0';
            suff += t[i][j] - '0';
            ans += p[j - (len - j)][pref - suff];
        }
    }

    std::cout << ans << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    // std::cin >> t;
    t = 1;
    while (t--) { sol(); }

    return 0;
}
