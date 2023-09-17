#include <bits/stdc++.h>
using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x, y, z;
    std::cin >> x >> y >> z;
    i64 threes = z / (3 * x + y);

    if (threes * (3 * x + y) >= z) {
        std::cout << threes * 3 << std::endl;
        return 0;
    }

    i64 redun = 0;
    for (int i = 0; i < 3; ++i) {
        if (i != 0) {
            redun += x;
        } else {
            redun += x + y;
        }

        if (threes * (3 * x + y) + redun >= z) {
            std::cout << threes * 3 + i + 1 << std::endl;
            return 0;
        }
    }

    // unreachable!

    return 0;
}
