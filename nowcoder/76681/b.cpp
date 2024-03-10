#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    int n;
    cin >> n;
    n -= 5;
    cout << setprecision(3) << fixed;
    if (n <= 0) {
        cout << 0. << endl;
    } else {
        double prob{};
        double fixer = 1.;
        constexpr const double SINGLE_PROB = 0.03;
        while (n >= 2) {
            prob += fixer * SINGLE_PROB;
            fixer *= 1. - SINGLE_PROB;
            n -= 2;
        }
        cout << prob << endl;
    }

    return 0;
}