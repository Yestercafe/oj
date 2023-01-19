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
#define N 300050
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

void unit_test_heap_construct_and_make() {
    vector<ll> v {82, 93, 87, 92, 86, 95};
    Heap<ll, less<ll>> heap(v.begin(), v.end());
    // cout << "before making: ";
    // o(heap.origin().cbegin(), heap.origin().cend());
    // heap.make();
    // cout << "after making: ";
    o(heap.origin().cbegin(), heap.origin().cend());
}

void unit_test_heap_push() {
    vector<ll> v {82, 93, 87, 92, 86, 95};
    Heap<ll, less<ll>> heap(v.begin(), v.end());
    heap.push(99);
    o(heap.origin().cbegin(), heap.origin().cend());
    {
        Heap<ll, less<ll>> heap;
        heap.push(0);
        o(heap.origin().cbegin(), heap.origin().cend());
        heap.push(1);
        o(heap.origin().cbegin(), heap.origin().cend());
        heap.push(2);
        o(heap.origin().cbegin(), heap.origin().cend());
        heap.push(3);
        o(heap.origin().cbegin(), heap.origin().cend());
        heap.push(4);
        o(heap.origin().cbegin(), heap.origin().cend());
        heap.push(5);
        o(heap.origin().cbegin(), heap.origin().cend());
    }
}

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
#ifndef ONLINE_JUDGE
    #if 0
        unit_test_heap_construct_and_make();
        unit_test_heap_push();
    #endif
#endif
        Heap<ll, greater<ll>> heap;
        for (int i = 0; i < n; ++i) {
            cin >> m;
            // 1. push 2. gettop 3. pop
            switch (m) {
                case 1:
                    cin >> m;
                    heap.push(m);
                    break;
                case 2:
                    cout << heap.gettop() << endl;
                    break;
                case 3:
                    heap.pop();
                    break;
            }
        }
        
    }
    return 0;
}
