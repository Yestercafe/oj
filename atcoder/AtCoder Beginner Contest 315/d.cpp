#include <bits/stdc++.h>
using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int h, w;
	std::cin >> h >> w;
	std::vector mat(h, std::vector<char>(w, '\0'));
	std::vector rc(h, std::map<char, int>{});
	std::vector cc(w, std::map<char, int>{});

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			std::cin >> mat[i][j];
			rc[i][mat[i][j]]++;
			cc[j][mat[i][j]]++;
		}
	}

	bool fin = true;
	std::array<int, 26> del_r{}, del_c{};
	// this loop will reach the fixed-point, loop (H+W) times at most.
	do {
		fin = true;
		// O(H)
		for (int i = 0; i < h; ++i) {
			if (rc[i].size() == 1 && rc[i].begin()->second > 1) {
				fin = false;
				del_c[rc[i].begin()->first - 'a']++;
				rc[i].clear();
			}
		}
		// O(W)
		for (int i = 0; i < w; ++i) {
			if (cc[i].size() == 1 && cc[i].begin()->second > 1) {
				fin = false;
				del_r[cc[i].begin()->first - 'a']++;
				cc[i].clear();
			}
		}

		// if del_r and del_c are not empty either, all letters which will be removed should be same.
		// O(26 * (H + W))
		for (int l = 0; l < 26; ++l) {
			char ch = l + 'a';
			if (del_r[l]) {
				for (int i = 0; i < h; ++i) {
					if ((rc[i][ch] -= del_r[l]) <= 0) {
						rc[i].erase(ch);
					}
				}
				del_r[l] = 0;
			}
			if (del_c[l]) {
				for (int i = 0; i < w; ++i) {
					if ((cc[i][ch] -= del_c[l]) <= 0) {
						cc[i].erase(ch);
					}
				}
				del_c[l] = 0;
			}
		}
	} while (!fin);

	int ans = 0;
	for (auto& r : rc) {
		for (auto [_, snd] : r) {
			ans += snd;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
