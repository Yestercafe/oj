#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int cntL[26] {};
    int cntU[26] {};
    for (auto c : s) {
        if (islower(c)) {
            cntL[c - 'a']++;
        } else if (isupper(c)) {
            cntU[c - 'A']++;
        }
    }
    int cnt_remain = 0;
    int pair_cnt = 0;
    for (int i = 0; i < 26; ++i) {
        int d = std::min(cntL[i], cntU[i]);
        pair_cnt += d;
        int remain = cntL[i] + cntU[i] - 2 * d;
        cnt_remain += remain / 2;
    }
    std::cout << pair_cnt + (cnt_remain > k ? k : cnt_remain) << std::endl;
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
