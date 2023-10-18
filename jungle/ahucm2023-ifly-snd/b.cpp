#include <iostream>
#include <queue>
#include <algorithm>
using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, nx, ny;
    std::cin >> n >> nx >> ny;

    std::priority_queue<int> pq;
    while (n--) {
        int a;
        std::cin >> a;
        pq.push(a);
    }

    int tx = 0, ty = 0;
    auto get_n_into_t = [&pq](int& t, int n) {
        while (n--) {
            t += pq.top();
            pq.pop();
        }
    };
    get_n_into_t(tx, nx);
    get_n_into_t(ty, ny);

    std::cout << (tx > ty ? "First" : "Second") << " Win" << std::endl;

    return 0;
}
