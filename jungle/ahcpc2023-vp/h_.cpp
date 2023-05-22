#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> g(n + 1, std::vector<std::pair<int, int>>{});
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		std::cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}

	std::unordered_set<int> s;
	for (int i = 2; i <= n; ++i)
		s.insert(i);
	std::vector<i64> ans(n + 1);
	ans[1] = INT_MAX;
	while (!s.empty()) {
		std::unordered_set<int> new_s;
		while (!s.empty()) {
			auto curr = *s.begin();
			s.erase(s.begin());

			i64 new_ans = 0;
			for (auto nxt : g[curr]) {
				auto neighbor = nxt.first, max_trans_power = nxt.second;
				new_ans += std::min(ans[neighbor], 1LL * max_trans_power);
			}
			// check fixed-point
			if (new_ans != ans[curr]) {
				// std::cout << "not get fixed-point: " << curr << " " << new_ans << ' ' << ans[curr] << std::endl;

				assert(new_ans >= ans[curr]);
				ans[curr] = new_ans;
				for (auto nxt : g[curr]) {
					if (nxt.first == 1) continue;
					new_s.insert(nxt.first);
				}

			} else {
				// reach fixed-point, pass
				// std::cout << "reach fixed-point: " << curr << std::endl;
			}
		}
		s.swap(new_s);
	}

	std::cout << ans[n] << std::endl;

	return 0;
}

/*
Start compiling and running...
Compile Successfully!
- Test Point #0: Wrong Answer, Time = 27 ms, Memory = 1356 KB, Score=0.0
- Test Point #1: Wrong Answer, Time = 169 ms, Memory = 3484 KB, Score=0.0
- Test Point #2: Wrong Answer, Time = 18 ms, Memory = 1316 KB, Score=0.0
- Test Point #3: Accepted, Time = 20 ms, Memory = 1276 KB, Score=10.0
- Test Point #4: Wrong Answer, Time = 23 ms, Memory = 1348 KB, Score=0.0
- Test Point #5: Accepted, Time = 26 ms, Memory = 2888 KB, Score=10.0
- Test Point #6: Wrong Answer, Time = 48 ms, Memory = 3060 KB, Score=0.0
- Test Point #7: Wrong Answer, Time = 48 ms, Memory = 3104 KB, Score=0.0
- Test Point #8: Wrong Answer, Time = 122 ms, Memory = 3692 KB, Score=0.0
- Test Point #9: Time Limit Exceed, Time = 1003 ms, Memory = 3668 KB, Score=0.0
Time Limit Exceed, Time = 1504 ms, Memory = 3692 KB, TotalScore = 20.0
Judge End
*/
