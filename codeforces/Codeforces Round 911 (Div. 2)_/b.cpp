#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    array<int, 3> arr;
    for (int i = 0; i < 3; ++i)
        cin >> arr[i];

    array<bool, 3> ans {};
    for (int i = 0; i < 3; ++i) {
        int m = arr[i], a = arr[(i + 1) % 3], b = arr[(i + 2) % 3];
        if ((a + b) % 2 == 1) {
            continue;
        }
        if (a > b) swap(a, b);  // make sure a <= b
        int diff = b - a;
        m += a;
        if (m != 0) {
            ans[i] = true;
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
