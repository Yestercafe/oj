#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum{};
    for (int& a : arr) {
        cin >> a;
        sum += a;
    }

    vector f(n + 1, vector<bool>(sum + 1));  // 6 * 10^7
    f[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (f[i - 1][j]) {
                f[i][j + arr[i - 1]] = f[i][j] = true;
            }
        }
    }

    int diff = numeric_limits<int>::max();
    for (int j = 0; j <= sum; ++j) {
        if (f.back()[j]) {
            diff = min(diff, abs(sum - 2 * j));
        }
    }

    cout << diff << endl;

    return 0;
}


// 6 6
// 4 4 4