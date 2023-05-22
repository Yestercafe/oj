#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	double a, b;
	std::cin >> a >> b;

	auto expr = [&](double x) {
		return std::sqrt(x * x + a) + std::sqrt((b - x) * (b - x) + 1);
	};

	double ans;
	if (a >= 0) {
		ans = std::min({
			expr((2 * a * b + std::sqrt(4 * a * b * b)) / (2 * (a - 1))),
			expr((2 * a * b - std::sqrt(4 * a * b * b)) / (2 * (a - 1)))
		});
	} else {
		ans = std::min({
			expr(std::sqrt(-a)),
			expr(-std::sqrt(-a))
		});
	}
	
	std::cout << std::fixed << std::setprecision(6)
	          << ans << std::endl;

	return 0;
}

/*
Start compiling and running...
Compile Successfully!
- Test Point #0: Accepted, Time = 24 ms, Memory = 1316 KB, Score=10.0
- Test Point #1: Accepted, Time = 17 ms, Memory = 1304 KB, Score=10.0
- Test Point #2: Accepted, Time = 18 ms, Memory = 1300 KB, Score=10.0
- Test Point #3: Accepted, Time = 18 ms, Memory = 1176 KB, Score=10.0
- Test Point #4: Accepted, Time = 17 ms, Memory = 1360 KB, Score=10.0
- Test Point #5: Accepted, Time = 16 ms, Memory = 1288 KB, Score=10.0
- Test Point #6: Accepted, Time = 64 ms, Memory = 1332 KB, Score=10.0
- Test Point #7: Accepted, Time = 17 ms, Memory = 1344 KB, Score=10.0
- Test Point #8: Accepted, Time = 17 ms, Memory = 1380 KB, Score=10.0
- Test Point #9: Accepted, Time = 16 ms, Memory = 1328 KB, Score=10.0
Accepted, Time = 224 ms, Memory = 1380 KB, TotalScore = 100.0
Judge End
*/
