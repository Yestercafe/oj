#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::string prev1, prev2;
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        auto curr = s.substr(i, 2);
        if (curr[1] != prev1[0] && curr != prev2) {
            ++ans;
        }
        prev2 = std::move(prev1);
        prev1 = std::move(curr);
    }
    std::cout << ans << std::endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        ::solve();
    }
    return 0;
}
