#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int last = INT_MAX;
    int pos = n;
    while (pos >= 0) {
        --pos;
        if (pos < 0) break;
        if (v[pos] <= last) {
            last = v[pos];
        } else {
            break;
        }
    }
    ++pos;

    int minn = INT_MAX;
    for (int i = 0; i < pos; ++i) {
        minn = min(minn, v[i]);
    }

    if (minn > v[pos]) {
        cout << pos << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
