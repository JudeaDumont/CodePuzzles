bool solution(int n, std::vector<std::vector<int>> r) {
	for (int i = 0; i <= n - 1; i++) {
		for (int ii = 0; ii <= n - 1; ii++) {
			if (ii != i) {
				bool oneroad = false;
				for (int v = 0; v < r.size(); v++) {
					if (i == r[v][0] || i == r[v][1]) {
						if (i == r[v][0] && ii == r[v][1]) {
							v = r.size();
							oneroad = true;
						}
						else if (i == r[v][1] && ii == r[v][0]) {
							v = r.size();
							oneroad = true;
						}
					}
				}
				if (!oneroad) {
					bool inefficient = true;
					for (int vv = 0; vv < r.size(); vv++) {
						bool f = false;
						int c;
						if (ii == r[vv][0] || ii == r[vv][1]) {
							f = true;
							if (ii == r[vv][0]) {
								c = r[vv][1];
							}
							else {
								c = r[vv][0];
							}
						}
						if (f == true) {
							for (int vvv = 0; vvv < r.size(); vvv++) {
								if (i == r[vvv][0] && c == r[vvv][1]) {
									inefficient = false;
								}
								else if (i == r[vvv][1] && ------------c == r[vvv][0]) {
									inefficient = false;
								}
							}
						}
					}
					if (inefficient) {
						return false;
					}
				}
			}
		}
	}
	return true;
}
// the problem i was having had to do with where in the iteration to check for two roads. I initially had the check for two roads in the loop for checking for oneroads. This was problematic because the return of false is an early one after ensuring that it is 3+roads. So, the check for 1 roads was exiting early, because after the first iteration into the container it would try and find a viable 2 road, and failing to do so, return early. lol, little bit rusty---------------------------------
