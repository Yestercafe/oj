#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using i64 = long long;
constexpr i64 M = 998244353;

i64 mplus(i64 a, i64 b) {
	return (a % M + b % M) % M;
}

struct S {
	i64 zero_cnt;
	i64 one_cnt;
	i64 weight;
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<std::vector<std::array<int, 2>>> edges(n + 1);
	for (int i = 1; i <= n; ++i) {
		int k;
		std::cin >> k;
		edges[i].reserve(k);
		for (int j = 0; j < k; ++j) {
			int other, w;
			std::cin >> other >> w;
			edges[i].push_back({other, w});
		}
	}

	std::vector<std::pair<bool, S>> vis(n + 1, {false, {0, 0, 0}});

	std::function<S(int)> dfs = [&](int i) -> S {
		i64 ans = 0, oc = 0, zc = 0;
		for (auto [nxt, w] : edges[i]) {
			// std::cout << "path " << i << ' ' << nxt << ' ' << w << '\n';
			if (!vis[nxt].first) {
				vis[nxt].first = true;
				vis[nxt].second = dfs(nxt);
			}
			
			auto snd = vis[nxt].second;
			switch (w) {
			case 0:
				ans = mplus(ans, mplus(snd.weight, oc * snd.zero_cnt));
				ans = mplus(ans, 1 * oc);
				oc = mplus(oc, snd.one_cnt);
				zc = mplus(zc, snd.zero_cnt + 1);
				break;
			case 1:
				oc += 1;
				ans = mplus(ans, mplus(snd.weight, oc * snd.zero_cnt));
				oc = mplus(oc, snd.one_cnt);
				zc = mplus(zc, snd.zero_cnt);
				break;
			}
		}

		// std::cout << "ret " << i << " {" << zc << ", " << oc << ", " << ans << "}\n"; 
		return {zc, oc, ans};
	};

	std::cout << dfs(1).weight << '\n';

	return 0;
}
