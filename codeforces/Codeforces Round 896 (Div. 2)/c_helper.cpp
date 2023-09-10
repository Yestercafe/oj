#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> ori(n);
    std::iota(ori.begin(), ori.end(), 0);
    auto perm = ori;

    int max = -1;

    do {
        std::set<int> v;
        for (int i = 0; i < n; ++i) {

            std::set<int> vis;
            vis.insert(ori[i]);
            vis.insert(perm[i]);

            int other;
            for (other = 0; other < n + 2; ++other) {
                if (vis.count(other)) continue;
                break;
            }

            v.insert(other);
        }

        int other;
        for (other = 0; other < n + 2; ++other) {
            if (v.count(other)) continue;
            break;
        }

        max = std::max(max, other);

    } while (std::next_permutation(perm.begin(), perm.end()));

    std::cout << max << std::endl;
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
