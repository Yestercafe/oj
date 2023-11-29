#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int dot_cnt = 0;
    int ans = 0;
    for (char c : s) {
        if (c == '.') {
            ++dot_cnt;
            continue;
        } else {
            if (dot_cnt == 1) {
                ++ans;
            } else if (dot_cnt == 2) {
                ans += 2;
            } else if (dot_cnt > 2) {
                ans = -1;
                dot_cnt = 0;
                break;
            }
            dot_cnt = 0;
        }
    }

    if (dot_cnt == 1) {
        ++ans;
    } else if (dot_cnt == 2) {
        ans += 2;
    } else if (dot_cnt > 2) {
        ans = -1;
    }

    cout << (ans < 0 ? 2 : ans) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
