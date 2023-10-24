#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, p;
    std::cin >> n >> p;

    std::vector<std::vector<std::array<i64, 3>>> g(n + 1);

    for (int i = 1; i <= n; ++i) {
        i64 f, s, k;
        std::cin >> f >> s >> k;
        g[f].push_back({i, k, s});
    }

    std::priority_queue<std::array<i64, 3>> pq;
    pq.push({0, p, 0});    // f, s, idx
    int ans = 0;
    i64 pn = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        if (pn < -top[0]) {
            std::cout << ans - 1 << std::endl;
            return 0;
        }

        ++ans;
        pn += top[1];
        for (auto nxt : g[top[2]]) {
            pq.push({-nxt[1], nxt[2], nxt[0]});
        }
    }

    std::cout << ans - 1 << std::endl;

    return 0;
}
