#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    if (n % 3 == 0) cout << "Second\n";
    else cout << "First\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
