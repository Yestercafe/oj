#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(X)
#else
#define dbg(X) cout<<#X": "<<(X)<<endl;
#endif
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050
typedef pair<ll, ll> pll;
#define mp make_pair

static inline ll pow2(ll a) { return a * a; }

pll calc(ll n, ll m) {
    if (n == 0)
        return mp(0, 0);
    ll len = 1ll << (n - 1), cnt = 1ll << (2 * n - 2);
    pll pos = calc(n - 1, m % cnt);
    ll x = pos.first, y = pos.second;
    ll z = m / cnt;
    switch (z) {
        case 0: return mp(y, x);
        case 1: return mp(x, y + len);
        case 2: return mp(x + len, y + len);
        case 3: return mp(2 * len - y - 1, len - x - 1);
    }
    return mp(0, 0);
}

int main()
{
    int _;
    cin >> _;
    while (_--) {
        ll n, p, q;
        cin >> n >> p >> q;
        pll pp = calc(n, p - 1);
        pll qq = calc(n, q - 1);
        //cout << pp.first << " " << pp.second << " " << qq.first << " " << qq.second << endl;
        cout << (ll) floor(10 * sqrt((double) pow2(pp.first - qq.first) + pow2(pp.second - qq.second)) + .5) << endl;
    }
    return 0;
}

