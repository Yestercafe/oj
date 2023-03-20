#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define N 300050
#if 0  // for C++20
namespace ranges = std::ranges;
#endif
// #define ONLINE_JUDGE
// Copy to use:
#ifndef ONLINE_JUDGE
#endif /* ONLINE_JUDGE */


const bool __SINGLETON = false;
void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> pref(n + 1);
    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
        i64 a;
        std::cin >> a;
        sum += a;
        pref[i + 1] = sum;
    }
    int l = 1, r = n;
    while (l <= r) {
        if (r - l < 5) {
            break;
        }
        int mid = l + (r - l) / 2;
        std::cout << "? " << mid - l + 1;
        for (int a = l; a <= mid; ++a) {
            std::cout << ' ' << a;
        }
        std::cout << std::endl;
        std::cout.flush();

        i64 weight;
        std::cin >> weight;
        // std::cout << "p weight: " << pref[mid] - pref[l - 1] << std::endl;
        if (weight > pref[mid] - pref[l - 1]) {
            r = mid + 1;
        } else {
            l = mid - 1;
        }
    }
    for (int i = l; i <= r; ++i) {
        std::cout << "? 1 " << i << std::endl;
        std::cout.flush();
        i64 weight;
        std::cin >> weight;
        if (weight > pref[i] - pref[i - 1]) {
            std::cout << "! " << i << std::endl;
            std::cout.flush();
            break;
        }
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    if (__SINGLETON) {
        ::solve();
    } else {
        i64 tt;
        cin >> tt;
        while (tt--) ::solve();
    }
    return 0;
}
