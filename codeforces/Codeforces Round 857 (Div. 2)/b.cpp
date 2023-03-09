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
namespace ranges = std::ranges;

const bool __SINGLETON = false;
void solve() {
    int n;
    std::cin >> n;
    int tot = 0, unex = 0;
    int aviary_cnt = 0;
    for (int i = 0; i < n; ++i) {
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            ++unex;
            if (tot == 0) {
                ++aviary_cnt;
            } else {
                aviary_cnt = std::max(aviary_cnt, (tot / 2 + 1) + unex);
            }
        } else {
            tot += unex;
            unex = 0;
            if (tot)
                aviary_cnt = std::max(aviary_cnt, tot / 2 + 1);
        }
    }
    std::cout << aviary_cnt << std::endl;
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
