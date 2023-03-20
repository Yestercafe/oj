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
i64 solve() {
    int n, m;
    std::pair<int, int> op, ed;
    std::cin >> n >> m
             >> op.first >> op.second >> ed.first >> ed.second;
    std::string dir;
    std::cin >> dir;
    std::set<std::pair<std::pair<int, int>, std::string>> path;
    std::pair<int, int> cur = op;
    i64 bounces = 0;
    while (true) {
        if (cur == ed) {
            return bounces;
        }
        if (path.contains({cur, dir})) {
            // std::cout << "baka!" << std::endl;
            return -1;
        }
        // std::cout << cur.first << ", " << cur.second << std::endl;
        if (dir == "DL") {
            bool bounce = false;
            if (cur.first == n) {
                dir[0] = 'U';
                bounce = true;
            }
            if (cur.second == 1) {
                dir[1] = 'R';
                bounce = true;
            }
            if (bounce) {
                ++bounces;
                continue;
            }
            int nx = cur.first + 1;
            int ny = cur.second - 1;
            path.insert({cur, dir});
            cur = make_pair(nx, ny);
        } else if (dir == "UL") {
            bool bounce = false;
            if (cur.first == 1) {
                dir[0] = 'D';
                bounce = true;
            }
            if (cur.second == 1) {
                dir[1] = 'R';
                bounce = true;
            }
            if (bounce) {
                ++bounces;
                continue;
            }
            int nx = cur.first - 1;
            int ny = cur.second - 1;
            path.insert({cur, dir});
            cur = make_pair(nx, ny);
        } else if (dir == "DR") {
            bool bounce = false;
            if (cur.first == n) {
                dir[0] = 'U';
                bounce = true;
            } if (cur.second == m) {
                dir[1] = 'L';
                bounce = true;
            }
            if (bounce) {
                ++bounces;
                continue;
            }
            int nx = cur.first + 1;
            int ny = cur.second + 1;
            path.insert({cur, dir});
            cur = make_pair(nx, ny);
        } else {   // UR
            bool bounce = false;
            if (cur.first == 1) {
                dir[0] = 'D';
                bounce = true;
            }
            if (cur.second == m) {
                dir[1] = 'L';
                bounce = true;
            }
            if (bounce) {
                ++bounces;
                continue;
            }
            int nx = cur.first - 1;
            int ny = cur.second + 1;
            path.insert({cur, dir});
            cur = make_pair(nx, ny);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (__SINGLETON) {
        std::cout << ::solve() << std::endl;
    } else {
        i64 tt;
        cin >> tt;
        while (tt--) std::cout << ::solve() << std::endl;
    }
    return 0;
}
