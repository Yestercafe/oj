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

const bool __SINGLETON = true;
void solve() {
    std::unordered_set<int> s;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        std::cin >> a;
        if (s.find(i) == s.end()) {
            s.insert(a);
        }
    }
    std::cout << n - s.size() << std::endl;
    bool fi = true;
    for (int i = 1; i <= n; ++i) {
        if (s.find(i) == s.end()) {
            if (fi) fi = false;
            else std::cout << ' ';
            std::cout << i;
        }
    }
    endl(std::cout);
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
