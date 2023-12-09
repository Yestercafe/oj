#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<pair<i64, i64>> intervals(n);
    i64 maxx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
        maxx = max(maxx, intervals[i].second);
    }

    auto intersectant = [](pair<i64, i64> a, pair<i64, i64> b) -> pair<i64, i64> {
        if (a.second < b.first || b.second < a.first) {
            return {-1, -1};
        }
        return {max(a.first, b.first), min(a.second, b.second)};
    };

    auto chk = [&](i64 mid) {
        pair<i64, i64> curr = {0, mid};
        for (auto iv : intervals) {
            auto nxt = intersectant(curr, iv);
            if (nxt.first >= 0) {
                curr = nxt;
                curr.first = max(0LL, curr.first - mid);
                curr.second += mid;
            } else {
                return false;
            }
        }
        return true;
    };

    i64 left = -1, right = maxx + 1;
    while (left + 1 < right) {
        i64 mid = left + right >> 1;
        if (chk(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
