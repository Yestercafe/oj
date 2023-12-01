#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
constexpr int inf = (1 << 30) - 1;

void sol() {
    int n;
    cin >> n;
    vector mat(n, vector(n, 0));
    vector candidates(n, inf);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
            if (i == j) continue;
            candidates[i] &= mat[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((candidates[i] | candidates[j]) != mat[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << candidates[i] << " \n"[i == n - 1];
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
