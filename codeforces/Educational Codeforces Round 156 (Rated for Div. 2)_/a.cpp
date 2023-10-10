#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n;
    std::cin >> n;

    if (n <= 6) {
        std::cout << "No\n";
        return;
    }
    // n > 6
    if (n % 3 != 0) {
        std::cout << "Yes\n"
                  << "1 2 " << n - 3 << '\n';
        return;
    }

    if (n - 5 == 4) {
        std::cout << "No\n";
        return;
    }

    std::cout << "Yes\n"
              << "1 4 " << n - 5 << '\n';
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
