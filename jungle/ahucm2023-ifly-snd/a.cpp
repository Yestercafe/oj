#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tot;
    std::cin >> tot;

    auto t = tot;
    int cnt_good = 0;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        auto good_enough = [=]() {
            int d1 = std::abs(a - b);
            int d2 = std::abs(a - c);
            int d3 = std::abs(b - c);
            return !(d1 > 2 || d2 > 2 || d3 > 2);
        };
        cnt_good += good_enough();
    }

    bool not_ans = (2 * (tot - cnt_good) > tot);

    int e, p;
    std::cin >> e >> p;
    if (2 * (p - e) > p) not_ans |= true;

    std::cout << (not_ans ? "No" : "Yes") << std::endl;

    return 0;
}
