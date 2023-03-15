#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define N 300050
// #define ONLINE_JUDGE
// Copy to use:
#ifndef ONLINE_JUDGE
#endif /* ONLINE_JUDGE */

typedef long long ll;

ll powmod(ll a, ll b, ll p) {
    ll ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

const bool __SINGLETON = true;
void solve() {
    i64 a, p, m;
    std::cin >> a >> p >> m;
    std::cout << (powmod(a, p, m) + m - 1) % m * powmod(a - 1, m - 2, m) % m << std::endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (__SINGLETON) {
        ::solve();
    } else {
        i64 tt;
        cin >> tt;
        while (tt--) ::solve();
    }
    return 0;
}
