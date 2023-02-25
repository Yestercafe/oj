#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    int ai, bi, min_gcd = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int gcd = std::gcd(v[i], v[j]);
            if (gcd < min_gcd) {
                min_gcd = gcd;
                ai = i;
                bi = j;
            }
        }
    }
    if (min_gcd > 2) {
        std::cout << "No" << std::endl;
        return ;
    }
    std::vector b(n, false);
    b[ai] = b[bi] = true;

    int selected = 2;
    while (min_gcd != 1 && selected != n) {
        selected++;
        int ci, minn_gcd = min_gcd;
        for (int i = 0; i < n; ++i) {
            if (!b[i]) {
                minn_gcd = std::gcd(minn_gcd, v[i]);
                if (minn_gcd < min_gcd) {
                    min_gcd = minn_gcd;
                    ci = i;
                }
            }
        }
        b[ci] = true;
        if (min_gcd > selected) {
            std::cout << "No" << std::endl;
            return ;
        }
    }

    std::cout << "Yes" << std::endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        ::solve();
    }
    return 0;
}
