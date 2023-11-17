#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n, q;
    cin >> n >> q;

    vector<int> qs(q);
    for (int i = 0; i < q; ++i) {
        cin >> qs[i];
    }

    for (int i = 1; i < n; ++i) {
        cout << i << ' ' << i + 1 << '\n';
    }
    
    int len = n - 1;
    for (auto s : qs) {
        if (len == s) {
            cout << "-1 -1 -1\n";
            continue;
        }
        cout << n << ' ' << len << ' ' << s << endl;
        len = s;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
