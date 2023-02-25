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
    int h = n / 2;
    for (int i = 0; i < h; ++i) {
        if (s[i] != s[n - 1 - i]) {
            s[i] = '2';
        }
    }
    auto new_end = std::unique(s.begin(), s.end());
    std::cout << (std::count(s.begin(), new_end, '2') <= 1 ? "Yes" : "No") << std::endl;
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
