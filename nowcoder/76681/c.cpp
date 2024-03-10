#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void Tomori() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& a : arr) cin >> a;
    if (!std::is_sorted(begin(arr), end(arr))) {
        cout << 0 << endl;
        return;
    }
    int min_diff = numeric_limits<int>::max();
    for (int i = 0; i < n - 1; ++i) {
        min_diff = min(min_diff, arr[i + 1] - arr[i]);
    }
    cout << min_diff / 2 + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ::Tomori();
    }

    return 0;
}

// 1 1 -> 2 0
// 2 4 -> 3 3 -> 4 2
// 2 5 -> 3 4 -> 4 3