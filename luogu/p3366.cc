// tags: Dijkstra 单源最短路
#include <bits/stdc++.h>
using i64 = long long;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;

    std::vector g(n, std::vector<std::pair<int, int>>());
    for (int i = 0; i < m; ++i) {
        int x, y, a;
        std::cin >> x >> y >> a;
        --x, --y;
        g[x].push_back({y, a});
        g[y].push_back({x, a});
    }

    std::priority_queue<std::array<int, 3>> pq;
    for (auto& nxt : g[0]) {
        pq.push({-nxt.second, 0, nxt.first});
    }

    std::vector<bool> vis(n);
    vis[0] = true;

    i64 ans = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (vis[top[2]]) continue;
        vis[top[2]] = true;
        ans -= 1LL * top[0];
        for (auto& nxt : g[top[2]]) {
            if (vis[nxt.first]) continue;
            pq.push({-nxt.second, top[2], nxt.first});
        }
    }

    if (std::find(vis.begin(), vis.end(), false) != vis.end()) {
        std::cout << "orz" << std::endl;
        return 0;
    }

    std::cout << ans << std::endl;

    return 0;
}
