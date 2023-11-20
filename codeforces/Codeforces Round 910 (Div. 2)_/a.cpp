#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt_b = count(begin(s), end(s), 'B');
    int cnt_a = n - cnt_b;
    
    if (cnt_b == k) {
        cout << "0\n";
        return;
    } else if (cnt_b < k) {    // (k - cnt_b) b->a
        int pos = 0, cnt = 0;
        while (pos < n) {
            if (s[pos] == 'A') {
                ++cnt;
            }
            if (cnt == k - cnt_b) {
                break;
            }
            ++pos;
        }

        cout << "1\n" << pos + 1 << " B\n";
    } else {
        int pos = 0, cnt = 0;
        while (pos < n) {
            if (s[pos] == 'B') {
                ++cnt;
            }
            if (cnt == cnt_b - k) {
                break;
            }
            ++pos;
        }
        cout << "1\n" << pos + 1 << " A\n";
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
