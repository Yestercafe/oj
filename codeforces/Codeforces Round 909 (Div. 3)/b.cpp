#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<i64> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        i64 v;
        cin >> v;
        pref[i + 1] = pref[i] + v;
    }

    i64 diff = 0;

    for (int q = 1; q * q <= n; ++q) {
        if (n % q == 0) {
            for (int chunk : {q, n / q}) {
                if (chunk == n) continue;
                i64 maxx = numeric_limits<i64>::min(), minn = numeric_limits<i64>::max();
                for (int i = 0; i < n / chunk; ++i) {
                    auto d = pref[(i * chunk) + chunk] - pref[i * chunk];
                    maxx = max(maxx, d);
                    minn = min(minn, d);
                }
                diff = max(diff, maxx - minn);
            }
        }
    }

    cout << diff << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
