#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[26] {};
    for (char c : s) {
        ++cnt[c - 'a'];
    }
    for (auto c : cnt) {
        if (c > n / 2) {
            cout << c - (n - c) << endl;
            return;
        }
    }
    if (n % 2) cout << 1 << endl;
    else cout << 0 << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
