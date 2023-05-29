#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::vector idx(n, INT_MAX);
		std::vector g(n, std::vector<std::pair<int, int>>{});
		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			std::cin >> a >> b;
			--a, --b;
			g[a].push_back({b, (int) g[b].size()});
			g[b].push_back({a, (int) g[a].size() - 1});
		}

		std::set<int> worklist;
		worklist.insert(0);

		std::function<bool(int, int)> dfs = [&](int i, int begin) {
			if (idx[i] == 0) return false;
			int m = std::min((int) g[i].size(), idx[i]);
			bool ret = false;
			for (int j = begin; j < m; ++j) {
				auto [other, inv_i] = g[i][j];
				if (idx[other] == INT_MAX) ret |= true;
				if (inv_i + 1 < idx[other]) {
					ret |= dfs(other, inv_i + 1);
					// std::cout << i << " -> " << other << std::endl;
				}
				worklist.insert(other);
			}
			idx[i] = std::min(idx[i], begin);
			return ret;
		};

		int ans = 0;
		while (!worklist.empty()) {
			// std::cout << "epoch " << ans << ", " << "len of worklist: " << worklist.size() << ":" << std::endl;
			int b = worklist.size();
			std::deque dq(worklist.begin(), worklist.end());
			worklist.clear();
			bool check = false;
			while (b--) {
				int f = dq.front();
				dq.pop_front();
				// std::cout << "to dfs " << f << std::endl;
				check |= dfs(f, 0);
			}
			if (check) ++ans;
		}

		std::cout << ans << std::endl;
	}

	return 0;
}