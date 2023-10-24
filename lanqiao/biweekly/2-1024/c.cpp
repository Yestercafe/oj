#include <bits/stdc++.h>
using i64 = long long;
constexpr int inf = 0x3fffffff;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s;
    std::cin >> n >> s;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int ans = v.back() - v.front();

    std::vector<int> d;
    d.reserve(n);

    for (int i = 0; i < n - 1; ++i) {
        d.push_back(v[i] - v[i + 1]);
    }

    std::partial_sort(d.begin(), d.begin() + s - 1, d.end());

    for (int i = 0; i < s - 1; ++i) {
        ans += d[i];
    }

    std::cout << ans << std::endl;

    return 0;
}
