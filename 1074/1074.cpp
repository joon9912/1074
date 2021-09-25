#include <iostream>
#include <cmath>
using namespace std;

int r, c;

void recur(int x, int y, int N) {
	static int count = -1;
	if (N == 1) {
		// N=1이면
		// 0,0 0,1 1,0 1,1 더하기	
		
		++count;
		if (x == r && y == c) {
			printf("%d", count);
		}

		++count;
		if (x == r && (y + 1) == c) {
			printf("%d", count);
		}

		++count;
		if ((x + 1) == r && y == c) {
			printf("%d", count);
		}

		++count;
		if ((x + 1) == r && (y + 1) == c) {
			printf("%d", count);
		}
	}
	else {
		if (r >= pow(2, N - 1) + x && c >= pow(2, N - 1) + y) {
			// 4사분면
			count += (pow(2,N) * pow(2,N) * 3) / 4;
			recur(pow(2, N - 1) + x, pow(2, N - 1) + y, N - 1);
		}
		else if (r >= pow(2, N - 1) + x && c <= pow(2, N - 1) + y) {
			// 3사분면
			count += pow(2, N) * pow(2, N) / 2;
			recur(pow(2, N - 1) + x, y, N - 1);
		}
		else if (r <= pow(2, N - 1) + x && c >= pow(2, N - 1) + y) {
			// 2사분면
			count += pow(2, N - 1) * pow(2, N - 1);
			recur(x, pow(2, N - 1) + y, N - 1);
		}
		recur(x, y, N-1);	
	}
}

int main() {
	int N;
	cin >> N >> r >> c;

	recur(0, 0, N);

	return 0;
}
