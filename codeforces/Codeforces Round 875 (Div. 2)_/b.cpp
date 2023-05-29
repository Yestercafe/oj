#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n;
    std::cin >> n;
    std::map<int, int> a, b;
    auto input_map = [n](auto& m) {
        int prev = -1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            int curr;
            std::cin >> curr;
            if (prev != curr) {
                if (prev > 0) {
                    m[prev] = std::max(m[prev], cnt);
                }
                prev = curr, cnt = 0;
            }
            ++cnt;
        }
        if (prev > 0) {
            m[prev] = std::max(m[prev], cnt);
        }
    };
    input_map(a);
    input_map(b);

    int ans = 1;
    for (auto [who, cnt] : a) {
        ans = std::max(ans, cnt + b[who]);
    }
    for (auto [who, cnt] : b) {
        ans = std::max(ans, cnt + a[who]);
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) ::sol();
    return 0;
}
