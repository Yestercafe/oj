#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
#define N 300050

void solve() {
    ll l, r;
    std::cin >> l >> r;

    ll twos = 0, twos_p = 1;
    while (l * 2 * twos_p <= r) {
        twos_p *= 2;
        twos++;
    }

    if (twos == 0) {
        std::cout << 1 << ' ' << r - l + 1 << std::endl;
        return ;
    }
    ll mediate = r / (twos_p / 2 * 3) - l + 1;
    std::cout << twos + 1 << ' ' << ((r / twos_p - l + 1) + (mediate > 0 ? mediate : 0) * twos) << std::endl;
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
