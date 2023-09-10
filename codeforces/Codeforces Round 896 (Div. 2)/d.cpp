#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    int n;
    std::cin >> n;
    std::vector<i64> v(n);
    i64 sum = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        sum += v[i];
    }

    if (sum % n != 0) {
        std::cout << "No" << '\n';
        return;
    }

    i64 avg = sum / n;
    int zcnt = 0;   // may be not used?

    std::map<int, int> out;

    for (int i = 0; i < n; ++i) {
        i64 redun = v[i] - avg;
        if (redun == 0) {
            ++zcnt;
            continue;
        }
        auto pos = std::abs(redun);

        // if ((pos & (pos - 1)) == 0) {
        //     int n = std::log2(pos);
        //     if (redun > 0) {
        //         ++out[n];
        //     } else {
        //         --out[n];
        //     }
        //     std::cout << "n = " << n << std::endl;
        //     continue;
        // }

        // pos = 2^n - 2^m
        int m = 0;
        while (pos % 2 == 0) {
            pos /= 2;
            ++m;
        }
        int n = -1;
        ++pos;
        if ((pos & (pos - 1)) == 0) {
            n = std::log2(pos);
        } else {
            std::cout << "No" << std::endl;
            return;
        }
        n += m;

        // std::cout << "n m = " << n << ' ' << m << std::endl;

        if (redun > 0) {
            ++out[n];
            --out[m];
        } else {
            --out[n];
            ++out[m];
        }

    }

    for (auto [w, c] : out) {
        if (c) {
            std::cout << "No" << std::endl;
            return;
        }
        // std::cout << "w c = " << w << ' ' << c << std::endl;
    }

    std::cout << "Yes" << std::endl;
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
