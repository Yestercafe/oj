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

struct Rope {
    int r;
    int b;
    Rope() : r{0}, b{0} {}
};

const bool __SINGLETON = true;
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Rope> ropes(n + 1);
    int a, b;
    char ac, bc;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> ac >> b >> bc;
        switch (ac) {
            case 'R':
                ropes[a].r = b;
                break;
            case 'B':
                ropes[a].b = b;
                break;
        }
        switch (bc) {
            case 'R':
                ropes[b].r = a;
                break;
            case 'B':
                ropes[b].b = a;
        }
    }

    unordered_set<int> s;
    int cyc = 0, acyc = 0;
    for (int i = 1; i <= n; ++i) {
        if (s.find(i) != s.end()) continue;
        s.insert(i);
        if (ropes[i].r) {
            int nxt = ropes[i].r;
            int prev = i;
            while (nxt && s.find(nxt) == s.end()) {
                s.insert(nxt);
                if (ropes[nxt].r == prev) {
                    prev = nxt;
                    nxt = ropes[nxt].b;
                } else {
                    prev = nxt;
                    nxt = ropes[nxt].r;
                }
            }
            if (s.find(nxt) != s.end()) {
                ++cyc;
                continue;
            } else {
                int nxt = ropes[i].b;
                int prev = i;
                while (nxt) {
                    s.insert(nxt);
                    if (ropes[nxt].r == prev) {
                        prev = nxt;
                        nxt = ropes[nxt].b;
                    } else {
                        prev = nxt;
                        nxt = ropes[nxt].r;
                    }
                }
            }
            ++acyc;
        } else if (ropes[i].b) {
            int nxt = ropes[i].b;
            int prev = i;
            while (nxt && s.find(nxt) == s.end()) {
                s.insert(nxt);
                if (ropes[nxt].r == prev) {
                    prev = nxt;
                    nxt = ropes[nxt].b;
                } else {
                    prev = nxt;
                    nxt = ropes[nxt].r;
                }
            }
            if (s.find(nxt) != s.end()) {
                ++cyc;
                continue;
            } else {
                int nxt = ropes[i].r;
                int prev = i;
                while (nxt) {
                    s.insert(nxt);
                    if (ropes[nxt].r == prev) {
                        prev = nxt;
                        nxt = ropes[nxt].b;
                    } else {
                        prev = nxt;
                        nxt = ropes[nxt].r;
                    }
                }
            }
            ++acyc;
        } else {
            ++acyc;
        }
    }
    std::cout << cyc << ' ' << acyc << std::endl;
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
