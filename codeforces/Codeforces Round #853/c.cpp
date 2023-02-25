#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050

void solve() {
    ll n, m;
    std::cin >> n >> m;
    std::vector<ll> cnt(n + m + 1);
    std::vector<ll> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        cnt[s[i]] = m + 1;
    }
    for (int i = m; i > 0; --i) {
        ll idx, c;
        std::cin >> idx >> c;
        --idx;
        cnt[s[idx]] -= i;
        cnt[c] += i;
        s[idx] = c;
    }

    ll ans = 2 * n * (m * (m + 1) / 2);
    for (int i = 1; i <= n + m; ++i) {
        ll c = cnt[i];
        ans -= (c * (c - 1)) / 2;
    }
    std::cout << ans << std::endl;
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
