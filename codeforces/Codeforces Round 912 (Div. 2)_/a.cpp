#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        int prev = INT_MIN;
        int a;
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            if (flag) continue;
            if (a < prev) {
                flag = true;
            }
            prev = a;
        }
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    } else {
        int a;
        for (int i = 0; i < n; ++i) {
            cin >> a;
        }
        cout << "YES" << endl;
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
