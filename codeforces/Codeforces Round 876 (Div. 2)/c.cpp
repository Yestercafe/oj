#include <bits/stdc++.h>
using i64 = long long;

template <typename T, typename Sum = T>
class Dst {
    std::vector<T> tree, lazy;
    std::vector<T> *arr;
    int n, root, n4, end;

    void pushdown(int cl, int cr, int p) {
        if (cl != cr && lazy[p]) {
            int cm = cl + (cr - cl) / 2;
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
            tree[p * 2] += lazy[p] * (cm - cl + 1);
            tree[p * 2 + 1] += lazy[p] * (cr - cm);
            lazy[p] = 0;
        }
    }

    Sum range_sum(int l, int r, int cl, int cr, int p) {
        if (l <= cl && cr <= r) return tree[p];
        pushdown(cl, cr, p);
        int m = cl + (cr - cl) / 2;
        Sum sum = 0;
        if (l <= m) sum += range_sum(l, r, cl, m, p * 2);
        if (r > m) sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
        return sum;
    }

    void range_add(int l, int r, T val, int cl, int cr, int p) {
        if (l <= cl && cr <= r) {
            lazy[p] += val;
            tree[p] += (cr - cl + 1) * val;
            return;
        }
        pushdown(cl, cr, p);
        int m = cl + (cr - cl) / 2;
        if (l <= m) range_add(l, r, val, cl, m, p * 2);
        if (r > m) range_add(l, r, val, m + 1, cr, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    void build(int s, int t, int p) {
        if (s == t) {
            tree[p] = (*arr)[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

public:
    explicit Dst(std::size_t n) {
        this->n = n;
        n4 = n * 4;
        tree = std::vector<T>(n4, 0);
        lazy = std::vector<T>(n4, 0);
        end = n - 1;
        root = 1;
    }

    explicit Dst(std::vector<T>& v) {
        n = v.size();
        n4 = n * 4;
        tree = std::vector<T>(n4, 0);
        lazy = std::vector<T>(n4, 0);
        arr = &v;
        end = n - 1;
        root = 1;
        build(0, end, 1);
        arr = nullptr;
    }

    void show(int p, int depth = 0) {
        if (p > n4 || tree[p] == 0) return;
        show(p * 2, depth + 1);
        for (int i = 0; i < depth; ++i) std::putchar('\t');
        std::printf("%d:%d\n", tree[p], lazy[p]);
        show(p * 2 + 1, depth + 1);
    }

    Sum range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

    void range_add(int l, int r, int val) { range_add(l, r, val, 0, end, root); }
};

void sol() {
	int n;
	std::cin >> n;
	std::vector<bool> arr(n);
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		arr[i] = a;
	}
	if (arr.back()) {
		std::cout << "NO" << std::endl;
		return;
	}

	Dst<int> dst(n + 1);
	std::vector<int> ans;
	ans.reserve(n);
	int e = n - 1;
	for (int i = n - 1; i > 0; --i) {
		bool b1 = (arr[i] + dst.range_sum(i + 1, i + 1)) % 2;
		bool b2 = (arr[i - 1] + dst.range_sum(i, i)) % 2;
		if (!b1 && b2) {
			dst.range_add(1, i, +1);
			ans.push_back(i);
		}
	}
	ans.resize(n);

	std::cout << "YES" << std::endl;
	for (int i = 0; i < n; ++i)
		std::cout << ans[n - 1 - i] << " \n"[i == n - 1];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) ::sol();
	return 0;
}
