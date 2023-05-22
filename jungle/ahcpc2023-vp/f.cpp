#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<i64> arr(n + 1);
	std::vector<std::vector<i64>> g(n + 1, std::vector<i64>{});
	std::vector<bool> vis(n + 1);
	std::vector<std::array<i64, 2>> f(n + 1, {0, 0});

	for (int i = 0; i < n - 1; ++i) {
		i64 a, b;
		std::cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i)
		std::cin >> arr[i];

	std::function<void(int)> dp = [&](int i) {
		vis[i] = true;
		i64 max = INT_MIN;
		for (auto nxt : g[i]) {
			if (vis[nxt]) continue;
			dp(nxt);
			f[i][0] += std::max(f[nxt][0], f[nxt][1]);
			f[i][1] += f[nxt][1];
			max = std::max(max, -f[nxt][1] + f[nxt][0] + arr[i] * arr[nxt]);
		}
		if (max != INT_MIN) f[i][1] += max;
	};

	dp(1);
	std::cout << std::max(f[1][0], f[1][1]) << std::endl;

	return 0;
}


/*
Start compiling and running...
Compile Successfully!
- Test Point #0: Wrong Answer, Time = 17 ms, Memory = 1168 KB, Score=0.0
- Test Point #1: Accepted, Time = 1261 ms, Memory = 65184 KB, Score=10.0
- Test Point #2: Wrong Answer, Time = 27 ms, Memory = 1388 KB, Score=0.0
- Test Point #3: Wrong Answer, Time = 24 ms, Memory = 1344 KB, Score=0.0
- Test Point #4: Accepted, Time = 1197 ms, Memory = 65104 KB, Score=10.0
- Test Point #5: Accepted, Time = 1233 ms, Memory = 65228 KB, Score=10.0
- Test Point #6: Accepted, Time = 1227 ms, Memory = 65100 KB, Score=10.0
- Test Point #7: Accepted, Time = 1255 ms, Memory = 65024 KB, Score=10.0
- Test Point #8: Accepted, Time = 1279 ms, Memory = 65092 KB, Score=10.0
- Test Point #9: Accepted, Time = 1244 ms, Memory = 65096 KB, Score=10.0
Wrong Answer, Time = 8764 ms, Memory = 65228 KB, TotalScore = 70.0
Judge End
*/
