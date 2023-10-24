#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        if (a > b) std::swap(a, b);
        
        if (a % 6 == 0) {
            if (b >= 2) {
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }
            continue;
        }

        if (b % 6 == 0) {
            if (a >= 2) {
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }
            continue;
        }

        if ((a % 3 == 0 && b % 2 == 0) || (a % 2 == 0 && b % 3 == 0)) {
            std::cout << "Yes" << std::endl;
            continue;
        }

        std::cout << "No" << std::endl;
    }

    return 0;
}
