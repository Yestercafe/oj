#include <bits/stdc++.h>
using i64 = long long;

std::vector<int> make_beautiful(std::string& s, std::vector<int>& idx, std::vector<int>& ans) {
	std::vector<int> pv1, pv2;
	std::vector<int> sv1, sv2;

	for (int o = 0, n_o = idx.size(); o < n_o; ++o) {
		int i = idx[o];
		if (s[i] == '(') {
			pv1.push_back(i);

			if (!sv2.empty()) {
				sv2.pop_back();
			} else {
				sv1.push_back(i);
			}
		} else {
			if (!pv1.empty()) {
				pv1.pop_back();
			} else {
				pv2.push_back(i);
			}

			sv2.push_back(i);
		}
	}

	if (pv1.size() > sv1.size()) {
		pv1.swap(sv1);
		pv2.swap(sv2);
	}

	pv1.reserve(pv1.size() + pv2.size());
	for (auto a : pv2) {
		pv1.push_back(a);
	}
	std::sort(pv1.begin(), pv1.end());
	for (auto i : pv1) {
		++ans[i];
	}

	return pv1;
}

void sol() {
	int n;
	std::string s;
	std::cin >> n >> s;

	if (std::count(s.begin(), s.end(), '(') != std::count(s.begin(), s.end(), ')')) {
		std::cout << -1 << std::endl;
		return;
	}

	std::vector<int> ans(n, 1);
	std::vector<int> idx(n);
	std::iota(idx.begin(), idx.end(), 0);
	int round = 0;
	do {
		idx = make_beautiful(s, idx, ans);
		++round;
	} while (!idx.empty());

	std::cout << round << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		::sol();
	}
	return 0;
}
