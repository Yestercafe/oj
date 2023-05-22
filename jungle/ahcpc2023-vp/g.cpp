#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::array<double, 3> a, b, c;
	std::cin >> a[0] >> a[1] >> a[2];
	std::cin >> b[0] >> b[1] >> b[2];
	std::cin >> c[0] >> c[1] >> c[2];

	double r;
	std::cin >> r;

	std::cout << std::fixed << std::setprecision(2)
	          << std::hypot(a[0] - b[0], a[1] - b[1], a[2] - b[2]) << std::endl;

	return 0;
}

/*
Start compiling and running...
Compile Successfully!
- Test Point #0: Accepted, Time = 19 ms, Memory = 1316 KB, Score=10.0
- Test Point #1: Accepted, Time = 18 ms, Memory = 1300 KB, Score=10.0
- Test Point #2: Wrong Answer, Time = 18 ms, Memory = 1228 KB, Score=0.0
- Test Point #3: Wrong Answer, Time = 18 ms, Memory = 1304 KB, Score=0.0
- Test Point #4: Accepted, Time = 18 ms, Memory = 1360 KB, Score=10.0
- Test Point #5: Wrong Answer, Time = 19 ms, Memory = 1332 KB, Score=0.0
- Test Point #6: Accepted, Time = 18 ms, Memory = 1176 KB, Score=10.0
- Test Point #7: Accepted, Time = 18 ms, Memory = 1356 KB, Score=10.0
- Test Point #8: Accepted, Time = 19 ms, Memory = 1288 KB, Score=10.0
- Test Point #9: Accepted, Time = 19 ms, Memory = 1340 KB, Score=10.0
Wrong Answer, Time = 184 ms, Memory = 1360 KB, TotalScore = 70.0
Judge End
*/
