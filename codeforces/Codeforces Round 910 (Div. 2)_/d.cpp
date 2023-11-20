#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    i64 ans = 0;
    int max_l = INT_MIN, min_r = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int l = min(a[i], b[i]), r = max(a[i], b[i]);
        max_l = max(max_l, l);
        min_r = min(min_r, r);
        ans += r - l;
    }
    cout << ans + 2LL * clamp(max_l - min_r, 0, INT_MAX) << '\n';
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
