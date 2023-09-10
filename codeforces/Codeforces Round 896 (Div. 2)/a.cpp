#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);

    int x = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        x ^= v[i];
    }

    if (n == 1) {
        std::cout << "1\n1 1\n";
        return;
    }

    if (n % 2 == 0) {
        std::cout << "2\n";
        std::cout << "1 " << n << '\n';
        std::cout << "1 " << n << '\n';
        return;
    } else {
        std::cout << "4\n";
        std::cout << "1 " << n - 1 << '\n';
        std::cout << "1 " << n - 1 << '\n';
        std::cout << n - 1 << ' ' << n << '\n';
        std::cout << n - 1 << ' ' << n << '\n';
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
