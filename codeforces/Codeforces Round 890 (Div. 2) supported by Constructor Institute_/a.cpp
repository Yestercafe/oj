#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
	    int prev = INT_MIN, curr;
	    int ans = 0;
	    while (n--) {
	    	std::cin >> curr;
	    	if (prev > curr) ans = std::max(ans, prev);
	    	prev = curr;
	    }
	    std::cout << ans << std::endl;
	}

	return 0;
}
