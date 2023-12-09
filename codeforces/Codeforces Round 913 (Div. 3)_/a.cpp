#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    char c;
    int r;
    cin >> c >> r;
    for (int ri = 1; ri <= 8; ++ri) {
        if (r == ri) continue;
        cout << c << ri << '\n';
    }
    for (char ci = 'a'; ci <= 'h'; ++ci) {
        if (c == ci) continue;
        cout << ci << r << '\n';
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
