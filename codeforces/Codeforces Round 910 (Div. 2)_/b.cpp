#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    i64 ans = 0;
    int min_beh = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] <= min_beh) {
            min_beh = v[i];
            continue;
        }

        int cnt_frag = (v[i] - 1) / min_beh + 1;
        ans += cnt_frag - 1;
        min_beh = v[i] / cnt_frag;
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
