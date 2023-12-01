#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<i64> suff(n + 1);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + arr[i];
    }

    i64 ans = suff[0];
    for (int i = n - 1; i >= 1; --i) {
        if (suff[i] > 0) ans += suff[i];
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
