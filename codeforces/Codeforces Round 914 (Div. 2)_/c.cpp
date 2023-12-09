#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<i64> arr(n);
    for (auto& a : arr) {
        cin >> a;
    }

    if (k >= 3) {
        cout << 0 << endl;
        return;
    }

    auto minn = *ranges::min_element(arr);
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                minn = min(minn, abs(arr[i] - arr[j]));
            }
        }
    } else {   // k == 2
        vector<i64> diffs;
        diffs.reserve(1LL * n * (n + 1) / 2);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto d = abs(arr[i] - arr[j]);
                minn = min(minn, d);
                diffs.push_back(d);
            }
        }
        ranges::sort(diffs);

        for (int i = 0; i < n; ++i) {
            auto p = ranges::lower_bound(diffs, arr[i]);
            if (p != end(diffs)) {
                minn = min(minn, abs(arr[i] - *p));
            }
            if (p != begin(diffs)) {
                --p;
                minn = min(minn, abs(arr[i] - *p));
            }

            p = ranges::upper_bound(diffs, arr[i]);
            if (p != end(diffs)) {
                minn = min(minn, abs(arr[i] - *p));
            }
        }
    }

    cout << minn << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}

