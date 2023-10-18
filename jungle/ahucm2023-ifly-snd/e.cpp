#include <bits/stdc++.h>
using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    
    --m;
    int round = m / (n - 1);
    if (round % 2) {    // rev
        std::cout << n - (m % (n - 1)) - 1 << std::endl;
    } else {
        std::cout << 2 + m % (n - 1) << std::endl;
    }

    return 0;
}