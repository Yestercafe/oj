#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    if (a.front() == b.front()) {
        std::cout << "YES" << std::endl;
        std::cout << a.front() << '*' << std::endl;
        return ;
    }
    if (a.back() == b.back()) {
        std::cout << "YES" << std::endl;
        std::cout << '*' << a.back() << std::endl;
        return ;
    }

    int n1 = a.length(), n2 = b.length();
    if (n1 < n2) {
        std::swap(a, b);
        std::swap(n1, n2);
    }

    unordered_set<std::string> m;
    for (int i = 0; i < n1 - 1; ++i) {
        std::string slice = a.substr(i, 2);
        m.insert(slice);
    }

    for (int i = 0; i < n2 - 1; ++i) {
        std::string slice = b.substr(i, 2);
        if (m.contains(slice)) {
            std::cout << "YES" << std::endl;
            std::cout << '*' << slice << '*' << std::endl;
            return ;
        }
    }
    std::cout << "NO" << std::endl;
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
