#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	double n, m, k;
	std::cin >> n >> m >> k;
	k = 1. - k / 100.;

	int yr;

	for (yr = 0; n >= m; ++yr)
		n *= k;

	std::cout << yr << std::endl;

	return 0;
}

/*
Start compiling and running...
Compile Successfully!
- Test Point #0: Accepted, Time = 19 ms, Memory = 1312 KB, Score=10.0
- Test Point #1: Accepted, Time = 18 ms, Memory = 1312 KB, Score=10.0
- Test Point #2: Accepted, Time = 17 ms, Memory = 1308 KB, Score=10.0
- Test Point #3: Accepted, Time = 17 ms, Memory = 1200 KB, Score=10.0
- Test Point #4: Accepted, Time = 20 ms, Memory = 1284 KB, Score=10.0
- Test Point #5: Accepted, Time = 16 ms, Memory = 1352 KB, Score=10.0
- Test Point #6: Accepted, Time = 17 ms, Memory = 1284 KB, Score=10.0
- Test Point #7: Accepted, Time = 17 ms, Memory = 1284 KB, Score=10.0
- Test Point #8: Accepted, Time = 17 ms, Memory = 1304 KB, Score=10.0
- Test Point #9: Accepted, Time = 17 ms, Memory = 1288 KB, Score=10.0
Accepted, Time = 175 ms, Memory = 1352 KB, TotalScore = 100.0
Judge End
*/
