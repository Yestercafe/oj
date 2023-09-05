#include <bits/stdc++.h>
using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	int ans = INT_MAX, a;
	while (n--) {
		std::cin >> a;
		a = std::abs(a);
		ans = std::min(a, ans);
	}

	std::cout << ans << std::endl;

	return 0;
}
