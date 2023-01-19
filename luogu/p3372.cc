#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <cstring>
#include <iterator>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(X)
#else
#define dbg(X) cout<<#X": "<<(X)<<endl;
#endif
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 100050
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair
#define L(x) ((x) * 2)
#define R(x) ((x) * 2 + 1)
#define M(l, r) (l + ((r - l) >> 1))

ll st[N << 2];
ll lazy[N << 2];
ll a[N];

template<typename It>
void o(It first, It last) {
    copy(first, last, ostream_iterator<decay_t<decltype(*first)>>(cout, ", "));
    endl(cout);
}

void init() {
    memset(st, 0, sizeof(st));
}

void build(int root, int l, int r) {
    if (l == r) {
        st[root] = a[l];
        return ;
    }

    auto m = M(l, r);
    build(L(root), l, m);
    build(R(root), m + 1, r);
    st[root] = st[L(root)] + st[R(root)];
}

void maintain(int root, int s, int t, int inc) {
    auto m = M(s, t);
    st[L(root)] += (m - s + 1) * inc;
    st[R(root)] += (t - m) * inc;
    lazy[L(root)] += inc;
    lazy[R(root)] += inc;
    lazy[root] = 0;
}

void update(int l, int r, int inc, int root, int s, int t) {
    if (l <= s && t <= r) {
        st[root] += (t - s + 1) * inc;
        lazy[root] += inc;
        return ;
    }
    if (lazy[root] && s != t) {
        maintain(root, s, t, lazy[root]);
    }
    auto m = M(s, t);
    if (l <= m) update(l, r, inc, L(root), s, m);
    if (m < r) update(l, r, inc, R(root), m + 1, t);
    st[root] = st[L(root)] + st[R(root)];
}

ll getsum(int l, int r, int root, int s, int t) {
    if (l <= s && t <= r)
        return st[root];
    int m = M(s, t);
    if (lazy[root]) {
        maintain(root, s, t, lazy[root]);
    }
    ll sum = 0;
    if (l <= m) sum += getsum(l, r, L(root), s, m);
    if (m < r)  sum += getsum(l, r, R(root), m + 1, t);
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int _ = 1;
    // cin >> _;
    while (_--) {
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        build(1, 1, n);
        
        for (int i = 0; i < m; ++i) {
            short instr;
            int l, r, u;
            cin >> instr;
            switch (instr) {
                case 1:
                    cin >> l >> r >> u;
                    update(l, r, +u, 1, 1, n);
                    break;
                case 2:
                    cin >> l >> r;
                    cout << getsum(l, r, 1, 1, n) << endl;
            }
        }
    }
    return 0;
}
