#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int nn;
    cin >> nn;
    ll p = 0, n = 0;
    int prev;
    for (int i = 0; i < nn; ++i) {
        int a;
        cin >> a;
        if (i > 0) {
            if (a - prev > 0) p += a - prev;
            else              n += prev - a;
        }
        prev = a;
    }
    if (n > p) swap(n, p);
    cout << p << '\n' << p - n + 1 << '\n';
    return 0;
}

