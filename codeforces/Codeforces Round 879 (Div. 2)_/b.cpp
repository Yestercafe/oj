#include <bits/stdc++.h>
using i64 = long long;
constexpr int inf = 0x3f3f3f3f;

bool upper(int a) {
    return a >> 1;
}

bool lower(int a) {
    return a & 1;
}

int gen(bool l, bool h) {
    int ret {};
    if (l) ret |= 1;
    if (h) ret |= 2;
    return ret;
}

const std::array<bool, 2> FT {true, false};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        std::string a, b;
        std::cin >> a >> b;
        
        if (a.length() < b.length()) {
            a = std::string(b.length() - a.length(), '0') + a;
        } else {
            b = std::string(a.length() - b.length(), '0') + b;
        }
        if (a > b) a.swap(b);

        int n = a.length();
        std::vector f(4, std::vector(4, -inf));
        
        for (int ia = a[0]; ia <= b[0]; ++ia) {
            int ula = gen(ia == a[0], ia == b[0]);
            for (int ib = a[0]; ib <= b[0]; ++ib) {
                int ulb = gen(ib == a[0], ib == b[0]);
                f[ula][ulb] = std::max(f[ula][ulb], std::abs(ib - ia));
            }
        }

        for (int i = 1; i < n; ++i) {
            std::vector nf(4, std::vector(4, -inf));
            for (int ula = 0; ula < 4; ++ula) {
                int ua = upper(ula) ? b[i] : '9', la = lower(ula) ? a[i] : '0';
                for (int ulb = 0; ulb < 4; ++ulb) {
                    int ub = upper(ulb) ? b[i] : '9', lb = lower(ulb) ? a[i] : '0';
                    for (int ia = la; ia <= ua; ++ia) {
                        for (int ib = lb; ib <= ub; ++ib) {
                            int nula = gen(lower(ula) && ia == a[i], upper(ula) && ia == b[i]);
                            int nulb = gen(lower(ulb) && ib == a[i], upper(ulb) && ib == b[i]);
                            nf[nula][nulb] = std::max(nf[nula][nulb], f[ula][ulb] + std::abs(ia - ib));
                        }
                    }
                }
            }
            f.swap(nf);
        }

        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                ans = std::max(ans, f[i][j]);
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
