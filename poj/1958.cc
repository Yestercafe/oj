#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 13
ll d[N], f[N];

int main()
{
    int _ = 1;
    while (_--) {
        ll n, m;
        d[1] = f[1] = 1ll;
        cout << f[1] << endl;
        for (n = 2; n <= 12; ++n) {
            d[n] = 2 * d[n - 1] + 1;
            f[n] = inf;
            for (int i = 0; i < n; ++i) {
                f[n] = min(f[n], 2 * f[i] + d[n - i]);
            }
            cout << f[n] << endl;
        }

    }
    return 0;
}

