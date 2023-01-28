#include <iostream>
#include <vector>
using namespace std;
#define N 3000050

int f[N];
vector<int> s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        int n;
        cin >> n;
        int maxi = N;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            s[y].push_back(x);
            maxi = max(maxi, y);
        }
    
        for (int i = 0; i <= maxi; ++i) {
            if (i) f[i] = f[i - 1];
            for (auto p : s[i]) {
                f[i] = max(f[i], (p - 1 >= 0 ? f[p - 1] : 0) + i-p+1);
            }
        }

        cout << f[maxi] << endl;
        
    }
    return 0;
}

