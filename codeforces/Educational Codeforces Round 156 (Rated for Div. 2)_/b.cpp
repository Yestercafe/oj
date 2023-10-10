#include <bits/stdc++.h>
using i64 = long long;

double dist(std::pair<int, int> a, std::pair<int, int> b) {
    return std::hypot(a.first - b.first, a.second - b.second);
}

void sol() {
    /*
    1. OP in A
    2. OP in B
    3. O in A, P in B
    4. O in B, P in A
        3.4. A and B are tangent at least => 2 * w >= dist(A, B)
    */

    std::pair<int, int> p, a, b;
    std::cin >> p.first >> p.second
             >> a.first >> a.second
             >> b.first >> b.second;
    std::pair<int, int> o {0, 0};

    double w1 = std::max(dist(o, a), dist(p, a));
    double w2 = std::max(dist(o, b), dist(p, b));

    double w3 = std::max(dist(a, b) / 2,
                         std::max(dist(o, a), dist(p, b)));
    double w4 = std::max(dist(a, b) / 2,
                         std::max(dist(o, b), dist(p, a)));

    std::cout << std::fixed << std::setprecision(6) << std::min({w1, w2, w3, w4}) << std::endl;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
