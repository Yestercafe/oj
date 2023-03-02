#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define N 300050

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::unordered_map<int, std::pair<int, int>> o[26], e[26];
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        int ns = s.length();
        int used_letter {};
        int cnt[26] {};
        for (auto c : s) {
            if (cnt[c - 'a'] == 0) used_letter |= (1 << (c - 'a'));
            if (used_letter == 0x3ffffff) break;
            cnt[c - 'a']++;
        }
        if (used_letter == 0x3ffffff) {
            continue;
        }
        int hash = 0;
        for (int j = 0; j < 26; ++j) {
            if (cnt[j] & 1) {
                hash |= (1 << j);
            }
        }
        if (ns & 1) {
            ++o[used_letter][hash];
        } else {
            ++e[used_letter][hash];
        }
    }

    ll ans = 0;
    for (int i = 0; i < 26; ++i) {
        for (auto [a, ca] : o[i]) {
            for (int j = 0; j < 26; ++j) {
                int mask = (1 << j);
                int mask_and_a = (a & mask);
                if (mask_and_a) continue;
                auto target = (0x3ffffff ^ mask ^ a);
                for (int k = 25 - i; k < 26; ++k) {
                    auto fnd = e[k].find(target);
                    if (fnd != e[k].end()) {
                        ans += (ca * fnd->second);
                        break;
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
