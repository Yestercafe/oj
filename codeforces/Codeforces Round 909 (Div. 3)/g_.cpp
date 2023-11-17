#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

vector<vector<int>> g;
vector<Fenwick<int>> fen;   // with perm[i] obtains children
vector<int> perm;
vector<bool> vis;
vector<int> path;

void dfs(int i) {
    // cout << i << endl;
    if (vis[i]) return;
    vis[i] = true;
    for (auto p : path) {
        fen[p].add(perm[i] + 1, 1);
    }

    path.push_back(i);
    for (auto nxt : g[i]) {
        dfs(nxt);
    }
    path.pop_back();
}

void sol() {
    int n, q;
    cin >> n >> q;
    g = vector<vector<int>>(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    perm = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        perm[a] = i;
    }

    fen = vector<Fenwick<int>>(n, Fenwick<int>(n + 1));
    vis = vector<bool>(n);
    path.clear();

    dfs(0);

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        if (fen[x - 1].rangeSum(l, r) == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
