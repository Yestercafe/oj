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
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 5005
int a[N][N];

int main()
{
    // 本题内存危机
    int _ = 1;
    //cin >> _;
    while (_--) {
        int n, m, x, y, v, xx = 0, yy = 0;
        cin >> n >> m;
        memset(a, 0, sizeof a);
        while (n--) {
            cin >> x >> y >> v;
            a[x + 1][y + 1] = v;
        }

        const int LIMIT = 5001;
        for (int i = 1; i <= LIMIT; ++i)
            for (int j = 1; j <= LIMIT; ++j) {
                a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            }
        
        int ans = 0ll;
        for (int i = m; i <= LIMIT; ++i)
            for (int j = m; j <= LIMIT; ++j) {
                ans = max(ans, 
                          a[i][j] - a[i - m][j] - a[i][j - m] + a[i - m][j - m]);
            }

        cout << ans << endl;
    }
    return 0;
}

