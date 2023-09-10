#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n, k, a, b;
    std::cin >> n >> k >> a >> b;
    i64 x, y;

    std::vector<std::pair<i64, i64>> maj(k), c(n);
    std::pair<i64, i64> start, end;

    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        if (i < k) {
            maj[i].first = x;
            maj[i].second = y;
        }
        c[i].first = x;
        c[i].second = y;

        if (i + 1 == a) {
            start.first = x;
            start.second = y;
        }
        if (i + 1 == b) {
            end.first = x;
            end.second = y;            
        }
    }

    auto dis = [](std::pair<i64, i64> a, std::pair<i64, i64> b) -> i64 {
        return std::abs(a.first - b.first) + std::abs(a.second - b.second);
    };

    if (k < 2) {
        std::cout << dis(start, end) << std::endl;
        return;
    }

    std::vector<int> idx(k);
    std::iota(idx.begin(), idx.end(), 0);

    // k >= 2
    std::partial_sort(idx.begin(), idx.begin() + 2, idx.end(), [&](int a, int b) {
        return dis(start, maj[a]) < dis(start, maj[b]);
    });
    int cs[2] = {idx[0], idx[1]};

    std::partial_sort(idx.begin(), idx.begin() + 2, idx.end(), [&](int a, int b) {
        return dis(end, maj[a]) < dis(end, maj[b]);
    });
    int ce[2] = {idx[0], idx[1]};

    i64 min = dis(start, end);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (cs[i] == ce[j]) continue;
            min = std::min(min, dis(start, maj[cs[i]]) + dis(end, maj[ce[j]]));
        }
    }

    std::cout << min << std::endl;
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
