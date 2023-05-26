#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    int a, b;
    std::cin >> a;
    for (int i = 1; i < n - 1; ++i)
        std::cin >> b;
    std::cin >> b;
    
    if (b > a) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}

