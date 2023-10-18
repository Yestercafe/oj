#include <bits/stdc++.h>
using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::map<int, int> m;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        int encode = 0;
        for (auto c : s) {
            encode |= (1 << (c - 'a'));
        }

        m[encode] = std::max(m[encode], static_cast<int>(s.length()));
    }

    int ans = 0;
    for (auto [e1, l1] : m) {
        for (auto [e2, l2] : m) {
            if (((e1 | e2) ^ e1) != e2) continue;
            ans = std::max(ans, l1 * l2);
        }
    }

    std::cout << ans;

    return 0;
}
