#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define N 15
#if 0  // for gcc C++20
namespace ranges = std::ranges;
#endif
// #define ONLINE_JUDGE
// Copy to use:
#ifndef ONLINE_JUDGE
#endif /* ONLINE_JUDGE */

const bool __SINGLETON = true;
void __solve() {
    i64 left, right;
    std::cin >> left >> right;
    std::vector<i64> ans1(N), ans2(N);
    std::vector<i64> f(N), tens(N);

    tens[0] = 1;
    // 求长度为 i 的数字中出现任意一个数的数量，不考虑前导 0
    for (int i = 1; i <= 13; ++i) {
        f[i] = f[i - 1] * 10 + tens[i - 1];
        tens[i] = 10 * tens[i - 1];
    }

    auto sol = [&](i64 n, std::vector<i64>& ans) {
        i64 r = n;
        std::vector<int> bits(N);
        int len = 0;
        // 将 n 拆分为十进制数位
        while (n != 0) {
            bits[++len] = n % 10;
            n /= 10;
        }
        for (int i = len; i > 0; --i) {
            // 考虑低 0~i-1 位：
            // 低 i 位的取值在区间 [0, bits[i]) 内时，0～9 可以在低 i-1 位任意地方取到，这个次数就是 f[i - 1]，
            // 对于 [0, bits[i]) 中的每一个第 i 位的取值，都能取到 f[i - 1]：
            for (int j = 0; j < 10; ++j) {
                ans[j] += f[i - 1] * bits[i];
            }
            // 考虑低 i 位：
            // 低 i 位在取 [0, bits[i]) 时，可以保证低 0～i-1 位满配：可以取到 0~10^{i-1} 使得低 i 位可以取得 j：
            for (int j = 0; j < bits[i]; ++j) {
                ans[j] += tens[i - 1];
            }
            // 移除 r 中的 bits[i] 对应的那一位，也就是 r 中的最高位
            r -= tens[i - 1] * bits[i];
            // 低 i 位取 bits[i] 时，有限制，此 bits[i] 只有在低 0～i-1 位在 0~r（r + 1 个数）范围内时才可能取到，即：
            ans[bits[i]] += r + 1;
            // 去除 leading zero 导致的多余计算
            ans[0] -= tens[i - 1];
        }
    };
    sol(right, ans1);
    sol(left - 1, ans2);
    for (int i = 0; i < 10; ++i) {
        std::cout << ans1[i] - ans2[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (__SINGLETON) {
        ::__solve();
    } else {
        i64 tt;
        cin >> tt;
        while (tt--) ::__solve();
    }
    return 0;
}
