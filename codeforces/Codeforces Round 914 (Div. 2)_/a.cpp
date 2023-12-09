#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    int a, b;
    pair<int, int> c1, c2;
    cin >> a >> b >> c1.first >> c1.second >> c2.first >> c2.second;
    vector<pair<int, int>> bias;
    if (a != b) {
        bias.emplace_back(a, b);
        bias.emplace_back(b, a);
        bias.emplace_back(-a, b);
        bias.emplace_back(-b, a);
        bias.emplace_back(a, -b);
        bias.emplace_back(b, -a);
        bias.emplace_back(-a, -b);
        bias.emplace_back(-b, -a);
    } else {
        bias.emplace_back(a, a);
        bias.emplace_back(-a, a);
        bias.emplace_back(a, -a);
        bias.emplace_back(-a, -a);
    }

    auto chk = [=](pair<int, int> p, pair<int, int> q) {
        auto dx = abs(p.first - q.first);
        auto dy = abs(p.second - q.second);
        if ((dx == a && dy == b) || (dx == b && dy == a)) {
            return true;
        }
        return false;
    };

    auto plus = [](pair<int, int> p, pair<int, int> q) {
        return make_pair(p.first + q.first, p.second + q.second);
    };

    int ans = 0;
    for (auto c : bias) {
        auto knight = plus(c, c1);
        if (chk(knight, c2)) {
            ++ans;
        }
    }

    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
