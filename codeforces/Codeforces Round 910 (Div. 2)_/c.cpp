#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    const int min_k = n + m - 2;
    if (k < min_k || k % 2 != min_k % 2) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    bool c = true;    // 'R'
    vector rows(n, vector<bool>(m - 1, false));
    vector cols(n - 1, vector<bool>(m, true));
    for (int i = 0; i < n - 1; ++i) {
        cols[i][0] = c;
        c = !c;
    }
    for (int i = 0; i < m - 1; ++i) {
        rows.back()[i] = c;
        c = !c;
    }

    cols.back()[m - 1] = cols.back()[m - 2] = rows.back().back();
    rows[n - 2].back() = !rows.back().back();

    for (int i = 0 ; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cout << (rows[i][j] ? 'R' : 'B') << " \n"[j == m - 2];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (cols[i][j] ? 'R' : 'B') << " \n"[j == m - 1];
        }
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
