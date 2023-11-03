#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n;
    std::cin >> n;
    std::vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> b(n);
    for (int i = 0; i < n - 1; ++i) {
        b[i + 1] = (b[i] ^ a[i]);
    }
    
    for (int k = 0; k < 31; ++k) {
        int one = (1 << k);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] & one) ++cnt;
            else --cnt;
        }

        if (cnt > 0) {
            for (int i = 0; i < n; ++i) {
                b[i] ^= one;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << b[i] << " \n"[i == n - 1];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;
    while (t--) { sol(); }

    return 0;
}
