#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    constexpr int N = 4005;
    std::vector<int> pref(N);
    for (int i = 1; i < N; ++i) {
        int cnt = 0;
        for (int f = 1; f * f <= i; ++f) {
            if (i % f == 0) {
                if (i / f == f) {
                    ++cnt;
                } else {
                    cnt += 2;
                }
            }
        }
        cnt %= 2;
        pref[i] = pref[i - 1] + cnt;
    }
    
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::cout << pref[n] << std::endl;
    }
    
    return 0;
}

