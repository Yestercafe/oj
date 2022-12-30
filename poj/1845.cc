#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <cstring>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(X)
#else
#define dbg(X) cout<<#X": "<<(X)<<endl;
#endif
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 9901;
#define N 30050
typedef pair<ll, ll> pii;
pii pc[N];

ll powmod(ll a, ll b, ll p) {
    ll ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

ll sum(ll p, ll c) {
    dbg(p);
    dbg(c);
    switch (c) { case 0: return 1ll; }
    if (c & 1) {
        return (1 + powmod(p, (c + 1) / 2, mod)) * sum(p, (c - 1) / 2) % mod;
    } else {
        return ((1 + powmod(p, c / 2, mod)) * sum(p, c / 2 - 1) + powmod(p, c, mod)) % mod;
    }
}


int main()
{
    int _ = 1;
    //cin >> _;
    while (_--) {
        ll n, m; 
        cin >> n >> m;
        int qyc = 0;
        for (ll i = 2; i * i <= n; ) {
            if (n % i == 0) {
                pc[qyc].first = i;
                pc[qyc].second = 0;
                while (n % i == 0) {
                    pc[qyc].second++;
                    n /= i;
                }
                ++qyc;
            }
            if (i == 2) ++i;
            else i += 2;
        }

        if (n != 1) {
            pc[qyc].first = n;
            pc[qyc++].second = 1;
        }

        ll ans = 1;
        for (int i = 0; i < qyc; ++i) {
            ans = ans * sum(pc[i].first, pc[i].second * m) % mod;
        }

        cout << ans << endl;
    }
    return 0;
}

