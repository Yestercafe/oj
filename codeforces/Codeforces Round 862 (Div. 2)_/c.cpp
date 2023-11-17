#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<i64> coe(n);
    for (auto& c : coe) cin >> c;
    ranges::sort(coe);
    
    while (m--) {
        i64 a, b, c;
        cin >> a >> b >> c;
        if (a * c <= 0) {
            cout << "NO\n";
        } else {
            auto kl = ranges::lower_bound(coe, b);
            if (kl != end(coe) && (*kl - b) * (*kl - b) < 4 * a * c) {
                cout << "YES\n" << *kl << '\n';
                continue;
            }
            if (kl != begin(coe)) {
                --kl;
                if ((*kl - b) * (*kl - b) < 4 * a * c) {
                    cout << "YES\n" << *kl << '\n';
                    continue;
                }
            }
            cout << "NO\n";
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        sol();
        // if (t != 0) cout << endl;
    }
    return 0;
}
