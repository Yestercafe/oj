#include <bits/stdc++.h>
using i64 = long long;

struct Dijkstra {
    std::vector<std::vector<std::pair<int, i64>>>& g;
    int n;
    static constexpr i64 inf = 0x6363636363636363;

    Dijkstra(std::vector<std::vector<std::pair<int, i64>>>& g)
        : g(g), n{static_cast<int>(g.size())} {}

    std::vector<i64> cal(int s) {
        std::vector<bool> vis(n);
        std::vector<i64> dis(n, inf);
        std::priority_queue<std::pair<i64, int>> pq;

        dis[s] = 0LL;
        pq.push({-0LL, s});

        while (!pq.empty()) {
            auto u = pq.top().second;
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (auto [v, w] : g[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({-dis[v], v});
                }
            }
        }

        return dis;
    }
};

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, s;
    std::cin >> n >> m >> s;
    --s;

    std::vector g(n, std::vector<std::pair<int, i64>>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        // g[v].push_back({u, w});
    }

    Dijkstra dij(g);
    auto ans = dij.cal(s);

    for (int i = 0; i < n; ++i) {
        std::cout << (ans[i] != Dijkstra::inf ? ans[i] : INT_MAX) << " \n"[i == n - 1];
    }

    return 0;
}
