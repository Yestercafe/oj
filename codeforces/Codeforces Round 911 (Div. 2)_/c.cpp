#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct Node {
    char c;
    int l, r;
    int p = 0;
};

void sol() {
    int n;
    cin >> n;
    vector<Node> v(n);
    vector<int> leaves;
    leaves.reserve(n / 2 + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].c;
    }

    for (int i = 0; i < n; ++i) {
        cin >> v[i].l >> v[i].r;
        --v[i].l, --v[i].r;
        if (v[i].l < 0 && v[i].r < 0) {
            leaves.push_back(i);
        }
    }

    deque<int> q;
    q.push_back(0);
    int ans = INT_MAX;
    while (!q.empty()) {
        int f = q.front();
        q.pop_front();

        int l = v[f].l, r = v[f].r;
        if (l >= 0) {
            v[l].p = v[f].p;
            if (v[f].c != 'L') {
                ++v[l].p;
            }
            q.push_back(l);
        }
        if (r >= 0) {
            v[r].p = v[f].p;
            if (v[f].c != 'R') {
                ++v[r].p;
            }
            q.push_back(r);
        }

        if (l < 0 && r < 0) {
            ans = min(ans, v[f].p);
        }
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
