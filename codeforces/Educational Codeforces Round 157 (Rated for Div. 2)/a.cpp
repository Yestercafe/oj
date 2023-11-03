#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int x, y, k;
    std::cin >> x >> y >> k;   // x: chest, y: key
    if (y <= x) {
        std::cout << x << std::endl;
        return;
    }
    int t = std::min(y - x, k);
    std::cout << x + t + 2 * ((y - x) - t) << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) { sol(); }

    return 0;
}
