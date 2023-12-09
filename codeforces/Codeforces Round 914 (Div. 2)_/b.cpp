#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<pair<i64, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    ranges::sort(arr);
    // cout << "  ";
    // for (auto [a, _] : arr) {
    //     cout << a << ' ';
    // }
    // cout << endl;

    vector<i64> pref_diff(n);
    i64 prefix_sum = 0;
    for (int i = 0; i < n; ++i) {
        pref_diff[i] = prefix_sum - arr[i].first;
        prefix_sum += arr[i].first;
    }

    // cout << "  ";
    // for (auto a : pref_diff) {
    //     cout << a << ' ';
    // }
    // cout << endl;

    vector<int> ans(n);
    int pos_bound = n;
    for (int i = n - 1; i >= 0; --i) {
        ans[arr[i].second] = max(i, pos_bound - 1);
        if (pref_diff[i] < 0) {
            pos_bound = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
