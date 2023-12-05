#include <bits/stdc++.h>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::priority_queue<int, std::deque<int>, std::greater<int>> pq;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        pq.push(a);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << pq.top() << " \n"[i == n - 1];
        pq.pop();
    }

    return 0;
} 
