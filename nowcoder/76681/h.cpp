#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define dbg(s) (cout << #s << ": " << s << endl)

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> s(n);
    priority_queue<int> inc;
    for (int& a : s) cin >> a;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        inc.push(a);
    }
        
    int cur = s[d - 1] + inc.top();

#ifdef TOMORI
    dbg(cur);
#endif

    inc.pop();
    while (d > 1 && !inc.empty()) {
        int nxt = s[d - 2];
        while (!inc.empty() && nxt + inc.top() > cur) {
#ifdef TOMORI
            dbg(1);
#endif
            inc.pop();
        }
        if (inc.empty()) {
            break;
        }
        --d;
    }

    cout << d << endl;

    return 0;
}
