#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    map<char, int> cnt;
    for (char ch : str) {
        ++cnt[ch];
    }

    int ans{}, diff_sum{};
    for (char i = 'a'; i <= 'z'; ++i) {
        ans += min(cnt[i], cnt[i + 'A' - 'a']);
        diff_sum += abs(cnt[i] - cnt[i + 'A' - 'a']) / 2;
    }

    ans += min(k, diff_sum);

    cout << ans << endl;

    return 0;
}
