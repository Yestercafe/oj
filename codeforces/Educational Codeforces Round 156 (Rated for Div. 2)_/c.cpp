#include <bits/stdc++.h>
using i64 = long long;

void sol() {
    std::string s;
    i64 p;
    std::cin >> s >> p;

    int x = 0;

    for (int len = s.length(); len > 0; --len) {
        if (p > len) {
            p -= len;
        } else {
            x = s.length() - len;
            break;
        }
    }

    std::string t;
    for (auto c : s) {
        while (x > 0 && !t.empty() && t.back() > c) {
            --x;
            t.pop_back();
        }
        t.push_back(c);
    }

    std::cout << t[p - 1];
}

int main()
{
    int t;
    std::cin >> t;
    while (t--) {
        sol();
    }
    std::cout << '\n';
    return 0;
}
