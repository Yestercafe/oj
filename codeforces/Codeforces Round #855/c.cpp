#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050

void solve() {
    int n;
    std::cin >> n;
    std::priority_queue<ll> pq;
    ll power = 0;
    for (int i = 0; i < n; ++i) {
        ll c;
        std::cin >> c;
        if (c == 0) {
            if (!pq.empty()) {
                power += pq.top();
                pq.pop();
            }
        } else {
            pq.push(c);
        }
    }
    std::cout << power << std::endl;
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
