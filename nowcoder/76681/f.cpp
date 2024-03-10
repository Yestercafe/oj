#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void filter_not_prime(vector<int>& arr) {
    int n = static_cast<int>(arr.size()) - 1;
    for (int p = 2; p * p <= n; ++p) {
        if (!arr[p]) continue;
        for (int f = 2; p * f <= n; ++f) {
            arr[f * p] = 0;
        }
    }
}

void filter_triangle(vector<int>& arr) {
    int n = static_cast<int>(arr.size()) - 1;
    int tri = 1, tri_nxt = 2;
    while (tri <= n) {
        arr[tri] = 0;
        tri += tri_nxt;
        ++tri_nxt;
    }
}

void filter_catalan(vector<int>& arr) {
    int n = static_cast<int>(arr.size()) - 1;
    int ctl = 1;
    int k = 1;
    while (ctl <= n) {
        arr[ctl] = 0;
#ifdef TOMORI
        cout << "ctl" << ctl << endl;
#endif
        ctl = (2 * (2 * k + 1) * ctl / (k + 2));
        ++k;
    }
}

void filter_even(vector<int>& arr) {
    int n = static_cast<int>(arr.size()) - 1;
    for (int i = 0; i <= n; i += 2) {
        arr[i] = 0;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> in(n + 1, 1);

    filter_not_prime(in);
    for (int i = 0, s = static_cast<int>(in.size()); i < s; ++i) {
        in[i] = 1 - in[i];
    }
    in[1] = 1;
#ifdef TOMORI
    for (int i = 1; i <= n; ++i) {
        cout << i << ": " << in[i] << endl;
    }
#endif

    filter_triangle(in);
    filter_catalan(in);
    filter_even(in);
    in[0] = 0;

    cout << accumulate(begin(in), end(in), 0) << endl;

    return 0;
}
