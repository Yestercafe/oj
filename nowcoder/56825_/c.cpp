#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    i64 ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
        int b;
        std::cin >> b;
        if (a[i] > b) {
            ans1 += a[i] - b;
        } else {
            ans2 += b - a[i];
        }
    }
    
    if (ans1 == ans2) {
        std::cout << ans1 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}

