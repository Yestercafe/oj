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
    std::vector<int> v(n + 1);
    int likes = 0;
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        if (a < 0) {
            a = -a;
        } else {
            ++pos;
        }
        --v[a];
        if (v[a] % 2) ++likes;
        else --likes;
    }

    for (int p = 1; p <= pos; ++p) {
        if (p != 1) std::cout << ' ';
        std::cout << p;
    }
    for (int i = pos, p = pos - 1; i < n; ++i, --p) {
        std::cout << ' ' << p;
    }
    std::cout << std::endl;

    bool firstIn = true;
    for (int i = 0; i < pos - likes; ++i) {
        if (firstIn) firstIn = false;
        else std::cout << ' ';
        std::cout << "1 0";
    }
    for (int i = 1; i <= likes; ++i) {
        if (firstIn) firstIn = false;
        else std::cout << ' ';
        std::cout << i;
    }
    std::endl(std::cout);
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
