#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define N 300050
// #define ONLINE_JUDGE
// Copy to use:
#ifndef ONLINE_JUDGE
#endif /* ONLINE_JUDGE */

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    int bound = static_cast<int>(std::sqrt(n)) + 1;
    for (int f = 2; f < n && f <= bound; ++f) {
        if (n % f == 0) return false;
    }
    return true;
}

const bool __SINGLETON = true;
void solve() {
    std::string s;
    std::cin >> s;
    int cnt[26] {};
    for (auto c : s) {
        int t = ++cnt[c - 'a'];
    }
    int minn = INT_MAX, maxn = -1;
    for (auto c : cnt) {
        if (c == 0) continue;
        minn = std::min(minn, c);
        maxn = std::max(maxn, c);
    }
    int diff = maxn - minn;
    if (isPrime(diff)) {
        std::cout << "Lucky Word" << std::endl << diff << std::endl;
    } else {
        std::cout << "No Answer\n0\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (__SINGLETON) {
        ::solve();
    } else {
        i64 tt;
        cin >> tt;
        while (tt--) ::solve();
    }
    return 0;
}
