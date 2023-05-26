#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// oi wiki
struct dsu {
  vector<size_t> pa, size, sum;

  explicit dsu(size_t size_)
      : pa(size_ * 2), size(size_ * 2, 1), sum(size_ * 2) {
    iota(pa.begin(), pa.begin() + size_, size_);
    iota(pa.begin() + size_, pa.end(), size_);
    iota(sum.begin() + size_, sum.end(), 0);
  }

  void unite(size_t x, size_t y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    pa[y] = x;
    size[x] += size[y];
    sum[x] += sum[y];
  }

  void move(size_t x, size_t y) {
    auto fx = find(x), fy = find(y);
    if (fx == fy) return;
    pa[x] = fy;
    --size[fx], ++size[fy];
    sum[fx] -= x, sum[fy] += x;
  }

  size_t find(size_t x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
};

void sol() {
	int n;
	std::cin >> n;
	dsu uf(n + 1);

	vector g(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		int neighbor;
		std::cin >> neighbor;
		uf.unite(neighbor, i);
		g[i] = neighbor;
	}

	std::set<int> s, t;
	for (int i = 1; i <= n; ++i) {
		auto parent = uf.find(i);
		s.insert(parent);
		if (i == g[g[i]]) {
			t.insert(parent);
		}
	}
	int alls = s.size(), twos = t.size();

	std::cout << alls - std::clamp(twos - 1, 0, twos) << ' ' << alls << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		::sol();
	}
}
