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
const int mod = 1e9 + 7;
#define N 10010
ll c[N];
typedef pair<int, int> pii;

int main()
{
    int _ = 1;
    //cin >> _;
    while (_--) {
        ll n, p, h, r;
        int a, b;
        cin >> n >> p >> h >> r;
        memset(c, 0, sizeof c);
        set<pii> ex;
        for (ll i = 0ll; i < r; ++i) {
            cin >> a >> b;
            if (a > b) swap(a, b);
            pii p = make_pair(a, b);
            if (ex.find(p) != ex.end()) continue;
            ex.insert(p);
            --c[a + 1];
            ++c[b];
        }
        
        for (int i = 1; i <= n; ++i) {
            c[i] += c[i - 1];
            cout << h + c[i] << endl;
        }
    }
    return 0;
}

