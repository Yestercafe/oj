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

    vector<i64> f(n + 1);
    for (int i = 0; i < n; ++i) {
        if (i > 0 && (v[i] & 1) == (v[i - 1] & 1)) {
            f[i + 1] = v[i];
            continue;
        }
        if (f[i] + v[i] >= 0) {
            f[i + 1] = max((i64) v[i], f[i] + v[i]);
            continue;
        } else {
            f[i + 1] = v[i];
        }
    }

    // for (auto a : f) {
    //     cout << a << ' ';
    // }
    // cout << endl;

    cout << *max_element(f.begin() + 1, f.end()) << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
