#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::vector mat(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> mat[i][j];
    
    std::vector f(n + 1, std::vector<i64>(m + 1, 0LL));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = std::max(f[i - 1][j], f[i][j - 1]) + mat[i][j];
        }
    }
    
    int T;
    std::cin >> T;
    while (T--) {
        int k;
        std::cin >> k;
        std::vector<std::pair<int, int>> ps(k);
        for (int i = 0; i < k; ++i) {
            std::cin >> ps[i].first >> ps[i].second;
        }
        i64 ans = f.back().back();
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i == j) continue;
                auto new_fj = f[ps[i].first][ps[i].second] + mat[ps[j].first][ps[j].second];
                if (new_fj < f[ps[j].first][ps[j].second]) {
                    continue;
                }
                auto g = f;
                g[ps[j].first][ps[j].second] = new_fj;
                for (int x = ps[j].first; x <= n; ++x) {
                    for (int y = ps[j].second; y <= m; ++y) {
                        g[x][y] = std::max(g[x][y], mat[x][y] + std::max(g[x - 1][y], g[x][y - 1]));
                    }
                }
                ans = std::max(ans, g.back().back());
            }
        }
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}
