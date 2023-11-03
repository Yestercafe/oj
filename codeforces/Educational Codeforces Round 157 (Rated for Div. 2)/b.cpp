#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n;
    std::cin >> n;
    std::vector<int> a(n * 2);
    for (int i = 0; i < n * 2; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += a[i + 1] - a[i] + a[n + i + 1] - a[n + i];
    }
    std::cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ' << a[i + n] << '\n';
    }
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
