#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <cstring>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(X)
#else
#define dbg(X) cout<<#X": "<<(X)<<endl;
#endif
typedef long long ll;
const double inf = 1e10;
#define N 100020
double a[N], b[N], p[N];
const double eps = 1e-5;

int main()
{
    int _ = 1;
    //cin >> _;
    while (_--) {
        int n, c;
        cin >> n >> c;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        
        double l = -1e6, r = 1e6;
        while (l + eps < r) {
            double mid = (l + r) / 2;
            for (int i = 1; i <= n; ++i)
                b[i] = a[i] - mid;
            for (int i = 1; i <= N; ++i)
                p[i] = p[i - 1] + b[i];
            double ans = -inf;
            double minn = inf;
            for (int i = c; i <= n; ++i) {
                minn = min(minn, p[i - c]);
                ans = max(ans, p[i] - minn);
            }
            if (ans >= 0)
                l = mid;
            else
                r = mid;
        }
        cout << int(r * 1000) << endl;
    }
    return 0;
}

