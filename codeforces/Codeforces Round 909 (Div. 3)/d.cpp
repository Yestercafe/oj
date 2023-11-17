#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    map<int, i64> cnt;

    i64 ans = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ans += cnt[a];
        if (a == 2) ans += cnt[1];
        else if (a == 1) ans += cnt[2];
        ++cnt[a];
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
