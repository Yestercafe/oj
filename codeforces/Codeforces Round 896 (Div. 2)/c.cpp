#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n, m;
    std::cin >> n >> m;

    if (m > n) {
        std::cout << n + 1 << '\n';

        for (int c = 0; c < m; ++c) {
            std::cout << c << " \n"[c == m - 1];
        }

        for (int r = 1; r < n; ++r) {
            for (int c = 0; c <= n; ++c) {
                std::cout << (c + (n + 1) - r) % (n + 1) << " \n"[c == m - 1];
            }
            for (int c = n + 1; c < m; ++c) {
                std::cout << c << " \n"[c == m - 1];
            }
        }

    } else {
        if (m == 1) std::cout << 0 << '\n';
        else std::cout << m << '\n';

        for (int c = 0; c < m; ++c) {
            std::cout << c << " \n"[c == m - 1];
        }

        for (int r = 1; r < m - 1; ++r) {
            for (int c = 0; c < m; ++c) {
                std::cout << (c + m - r) % m << " \n"[c == m - 1];
            }
        }

        for (int r = std::max(1, m - 1); r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                std::cout << c << " \n"[c == m - 1];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) {
        ::sol();
    }
    return 0;
}
