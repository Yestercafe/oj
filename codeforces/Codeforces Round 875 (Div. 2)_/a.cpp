#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n;
    std::cin >> n;
    for (int i = 0, _; i < n; ++i) {
        int a;
        std::cin >> a;
        std::cout << n + 1 - a << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) ::sol();
    return 0;
}
