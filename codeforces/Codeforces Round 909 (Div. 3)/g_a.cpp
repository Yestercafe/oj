// hints: 可持久化线段树，主席树
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct Node {
    int l, r, val;
};

vector<int> vers;

vector<vector<int>> g;
int ts;
vector<int> it, ot;

vector<Node> track;   // len >= logN * N   

int update(int o, int l, int r, int x) {
    int ver = ++ts;
    track[ver] = track[o];
    ++track[ver].val;
    if (l == r) return ver;

    int mid = l + r >> 1;
    if (x <= mid) {
        track[ver].l = update(track[o].l, l, mid, x); 
    } else {
        track[ver].r = update(track[o].r, mid + 1, r, x);
    }

    return ver;
}

// a and b are history versions, b is older than a
// l and r is query range
// x and y is range to find
int query(int a, int b, int l, int r, int x, int y) {
    if (x <= l && r <= y) return track[b].val - track[a].val;
    int mid = l + r >> 1;
    int ret = 0;
    if (x <= mid) {
        ret += query(track[a].l, track[b].l, l, mid, x, y);
    }
    if (mid < y) {
        ret += query(track[a].r, track[b].r, mid + 1, r, x, y);
    }
    return ret;
}

void dfs(int i, int pa) {
    it[i] = ++ts;
    for (auto nxt : g[i]) {
        if (nxt == pa) continue;
        dfs(nxt, i);
    }
    ot[i] = ts;
}

void sol() {
    int n, q;
    cin >> n >> q;
    g = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ts = 0;
    it = vector<int>(n + 1);
    ot = vector<int>(n + 1);
    dfs(1, -1);
    ts = 0;

    vers = vector<int>(n + 1);
    track = vector<Node>(20 * n);   // N == 1e5, logN ~= 16
    for (int i = 1; i <= n; ++i) {
        int perm;
        cin >> perm;
        vers[i] = update(vers[i - 1], 1, n, it[perm]);
    }

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << (query(vers[l - 1], vers[r], 1, n, it[x], ot[x]) ? "YES" : "NO") << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
