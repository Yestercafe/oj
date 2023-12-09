#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void sol() {
    string s;
    cin >> s;
    auto n = s.length();
    vector<bool> del(n);
    int b_cnt = 0, B_cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'B') {
            del[i] = true;
            ++B_cnt;
            continue;
        } else if (s[i] == 'b') {
            del[i] = true;
            ++b_cnt;
            continue;
        } else if (islower(s[i]) && b_cnt > 0) {
            del[i] = true;
            --b_cnt;
        } else if (isupper(s[i]) && B_cnt > 0) {
            del[i] = true;
            --B_cnt;
        }
    }

    string s1;
    s1.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (del[i]) {
            continue;
        }
        s1.push_back(s[i]);
    }

    cout << s1 << endl;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
