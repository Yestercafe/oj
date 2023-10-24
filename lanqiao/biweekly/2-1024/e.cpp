#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n;
    std::cin >> n;
    std::vector<std::vector<std::array<i64, 2>>> g(n);

    i64 ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        i64 v, u, w;
        std::cin >> v >> u >> w;
        --v, --u;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
        ans += 2 * w;
    }

    auto bfs = [&](int sp) -> std::pair<int, i64> {
        std::deque<std::array<i64, 2>> q;
        std::vector<bool> vis(n);
        q.push_back({sp, 0});
        vis[sp] = true;
        i64 max_path = -1;
        int max_path_i = -1;
        while (!q.empty()) {
            auto f = q.front();
            q.pop_front();
            for (auto nxt : g[f[0]]) {
                if (vis[nxt[0]]) continue;
                vis[nxt[0]] = true;
                auto path = f[1] + nxt[1];
                if (path > max_path) {
                    max_path = path;
                    max_path_i = nxt[0];
                }

                q.push_back({nxt[0], path});
            }
        }

        return {max_path_i, max_path};
    };

    auto [e, _] = bfs(0);
    auto [__, dans] = bfs(e);

    std::cout << ans - dans << std::endl;

    return 0;
}
