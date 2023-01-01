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
#define N 300050

int main()
{
    int _ = 1;
    //cin >> _;
    while (_--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        auto maxx = -inf;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            maxx = max(maxx, v[i]);
        }

        auto check = [&](int l) {
            int slice = 0;
            for (auto& a : v) slice += a / l;
            return slice >= k;
        };
        
        int left = 0, right = maxx + 1;
        while (left + 1 < right) {
            auto mid = left + right >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        cout << left << endl;
    }
    return 0;
}

