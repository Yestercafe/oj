#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		--n;

		if (n % 3 == 0) {
			std::cout << 1LL * 4 * (n / 3) + 4 << std::endl;
		} else {
			int d = n / 3;
			int m = n % 3;
			std::cout << 1LL * 2 * (2 * d + m) + 3 << std::endl;
		}
	}

	return 0;
}

/*
Start compiling and running...
Compile Successfully!
- Test Point #0: Accepted, Time = 19 ms, Memory = 1296 KB, Score=10.0
- Test Point #1: Accepted, Time = 17 ms, Memory = 1372 KB, Score=10.0
- Test Point #2: Accepted, Time = 17 ms, Memory = 1308 KB, Score=10.0
- Test Point #3: Accepted, Time = 18 ms, Memory = 1208 KB, Score=10.0
- Test Point #4: Accepted, Time = 17 ms, Memory = 1316 KB, Score=10.0
- Test Point #5: Accepted, Time = 17 ms, Memory = 1288 KB, Score=10.0
- Test Point #6: Accepted, Time = 17 ms, Memory = 1388 KB, Score=10.0
- Test Point #7: Accepted, Time = 17 ms, Memory = 1284 KB, Score=10.0
- Test Point #8: Accepted, Time = 21 ms, Memory = 1336 KB, Score=10.0
- Test Point #9: Accepted, Time = 20 ms, Memory = 1256 KB, Score=10.0
Accepted, Time = 180 ms, Memory = 1388 KB, TotalScore = 100.0
Judge End
*/
