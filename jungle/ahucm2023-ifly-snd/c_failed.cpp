#include <bits/stdc++.h>
using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, m;
    std::cin >> n >> k >> m;
    std::vector<std::pair<int, int>> v(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> v[i].first >> v[i].second;
    }

    std::sort(v.begin(), v.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    std::priority_queue<int> coupon;    // store negative diff

    int ans = 0;
    bool flag = true;
    for (int i = 0; i < k; ++i) {
        if (m - v[i].second >= 0) {
            m -= v[i].second;
            ++ans;
            coupon.push(v[i].second - v[i].first);   // assert eval a non-positive
        } else {
            flag = false;
            break;
        }
    }

    if (flag) for (int i = k; i < n; ++i) {
        auto [p, c] = v[i];
        auto d1 = p;
        auto d2 = -coupon.top() + c;
        auto d = std::min(d1, d2);
        // std::cout << "m" << m << std::endl;

        // Try PlumYu's HACK: failed
        // ----------------------------------------------------
        if (!coupon.empty() && p - c + coupon.top() > 0) {
            m += p - c + coupon.top();
            coupon.pop();
            coupon.push(c - p);
        }
        // ----------------------------------------------------

        if (m - d >= 0) {
            m -= d;
            if (d == d2) {
                coupon.pop();
                coupon.push(c - p);
            }
            ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
