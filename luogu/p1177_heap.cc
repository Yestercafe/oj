#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <cstring>
#include <iterator>
#include <exception>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(X)
#else
#define dbg(X) cout<<#X": "<<(X)<<endl;
#endif
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 100050
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair

template<typename It>
void o(It first, It last) {
    copy(first, last, ostream_iterator<decay_t<decltype(*first)>>(cout, ", "));
    endl(cout);
}

template<typename T = int, typename Comp = std::less<T>>
class Heap {
public:
    Heap() { c.reserve(64); }
    explicit Heap(size_t size) { c.reserve(size < 64 ? 64 : size); }
    template<typename It>
    Heap(It first, It last) {
        auto n = distance(first, last);
        c.reserve(n < 64 ? 64 : n);
        copy(first, last, back_inserter(c));
        this->make();
    }
    void make() {
        auto len = c.size();
        int i = len - 1;
        while (i != 0) {
            auto p = get_parent(i);
            adjust(p);
            decltype(p) np;
            do {
                --i;
                np = get_parent(i);
            } while (np == p);
        }
    }
    void push(const T& t) {
        c.push_back(t);
        size_t i = c.size() - 1;
        while (i != 0) {
            auto p = get_parent(i);
            if (comp(c[p], c[i])) {
                swap(c[p], c[i]);
            } else {
                break;
            }
            i = p;
        }
    }
    T pop() {
        if (this->empty()) {
            using namespace std::literals;
            throw std::out_of_range("The heap is empty while poping"s);
        }
        swap(c.front(), c.back());
        auto ret = std::move(c.back());
        c.pop_back();
        if (c.size() != 1) {
            adjust(0);
        }
        return std::move(ret);
    }
    const vector<T>& origin() const {
        return this->c;
    }
    T gettop() const {
        return this->c.front();
    }
    size_t size() const {
        return c.size();
    }
    bool empty() const {
        return c.size() == 0;
    }
private:
    static size_t get_left(size_t root) {
        return root * 2 + 1;
    }
    static size_t get_right(size_t root) {
        return root * 2 + 2;
    }
    static size_t get_parent(size_t child) {
        return (child - 1) >> 1;
    }
    void adjust(size_t p) {
        auto len = c.size();
        auto left = get_left(p);
        auto right = get_right(p);
        if (left < len && right >= len) {
            if (comp(c[p], c[left])) {
                swap(c[p], c[left]);
            }
        } else if (right < len) {
            auto cpl = comp(c[p], c[left]);
            auto cpr = comp(c[p], c[right]);
            auto clr = comp(c[left], c[right]);
            if (cpl && !cpr || cpl && cpr && !clr) {
                swap(c[p], c[left]);
                adjust(left);
            } else if (!cpl && cpr || cpl && cpr && clr) {
                swap(c[p], c[right]);
                adjust(right);
            }
        }
    }
private:
    vector<T> c;
    Comp comp;
};

ll arr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // init();
    int _ = 1;
    // cin >> _;
    while (_--) {
        ll n, m;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Heap<int, greater<int>> heap(arr, arr + n);
        auto firstIn = true;
        while (!heap.empty()) {
            if (firstIn) firstIn = false;
            else cout << ' ';
            cout << heap.pop();
        } endl(cout);
    }
    return 0;
}
