#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    int a, b, c;
    int n;
    cin >> a >> b >> c >> n;

    int cnt{};
    while (n--) {
        int x;
        cin >> x;
        if (b < x && x < c) {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}