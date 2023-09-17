#include <bits/stdc++.h>
using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    constexpr std::string_view t = "meituan";
    int k = 0;
    for (int i = 0; i < n; ++i) {
        bool skip = false;
        for (int j = 0; j < m; ++j) {
            char ch;
            std::cin >> ch;
            if (!skip && k < t.size() && t[k] == ch) {
                skip = true;
                ++k;
            }
        }
    }

    if (k == t.size()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}
