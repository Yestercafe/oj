// tags: 矩阵快速幂
#include <bits/stdc++.h>
using i64 = long long;
i64 mod;

i64 mod_add(i64 a, i64 b) {
    return (a + b) % mod;
}

i64 mod_mul(i64 a, i64 b) {
    return (a * b) % mod;
}

std::array<i64, 4> mat_mul(std::array<i64, 4> a, std::array<i64, 4> b) {
    std::array<i64, 4> ans;
    ans[0] = mod_add(mod_mul(a[0], b[0]), mod_mul(a[1], b[2]));
    ans[1] = mod_add(mod_mul(a[0], b[1]), mod_mul(a[1], b[3]));
    ans[2] = mod_add(mod_mul(a[2], b[0]), mod_mul(a[3], b[2]));
    ans[3] = mod_add(mod_mul(a[2], b[1]), mod_mul(a[3], b[3]));
    return ans;
}

std::array<i64, 4> mat_pow(std::array<i64, 4> mat, i64 idx) {
    std::array<i64, 4> ans {1, 0, 0, 1};
    while (idx != 0) {
        if (idx % 2) {
            ans = mat_mul(ans, mat);
        }
        mat = mat_mul(mat, mat);
        idx /= 2;
    }
    return ans;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    i64 n;
    std::cin >> n >> mod;

    std::array<i64, 4> p {0, 1, 1, 1};
    auto pn = mat_pow(p, n);
    std::cout << pn[2] << std::endl;

    return 0;
}
