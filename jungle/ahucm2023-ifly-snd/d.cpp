#include <bits/stdc++.h>
using i64 = long long;
constexpr int inf = 1061109567;

// https://oi-wiki.org/graph/shortest-path/
constexpr int maxn = 405;
struct edge {
  int v, w;
};

struct node {
  int dis, u;

  bool operator>(const node& a) const { return dis > a.dis; }
};

std::vector<edge> e[maxn];
int dis[maxn], vis[maxn];

void dijkstra(int n, int s) {
  std::priority_queue<node, std::vector<node>, std::greater<node> > q;
  memset(dis, 63, sizeof(dis));
  memset(vis, 0, sizeof(vis));

  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    for (int i = 0; i < m; ++i) {
        int x, y, w;
        std::cin >> x >> y >> w;
        e[x].push_back({y, w});
        e[y].push_back({x, w});
    }

    std::vector dd(maxn, std::vector(maxn, 0));
    for (int i = 1; i < maxn; ++i) {
        dijkstra(maxn, i);
        for (int j = 0; j < maxn; ++j) {
            dd[i][j] = dis[j];
        }
    }

    // 1e8: ??
    int ans = INT_MAX;
    for (int bias = 0; bias < n; ++bias) {
        int cans = 0;
        bool broken = false;
        for (int i = 0; i < n; ++i) {
            if (dd[a[i]][b[(i + bias) % n]] >= inf) {
                broken = true;
                break;
            }
            cans += dd[a[i]][b[(i + bias) % n]];
        }
        if (broken) continue;
        ans = std::min(ans, cans);
    }

    std::cout << (ans == INT_MAX ? -1 : ans) << std::endl;

    return 0;
}
