#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050

ll powmod(ll a, ll b, ll p) {
    ll ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

int main()
{
    int _;
    cin >> _;
    while (_--) {
        ll n, m; 
        cin >> m >> n;
        ll a, b;
        ll ans = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> a >> b;
            ans = (ans + powmod(a, b, m)) % m;
        }
        cout << ans << endl;
    }
    return 0;
}

