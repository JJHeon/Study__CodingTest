/*
@Title		: 백준
@Name		: 시험 감독
@First0		: 20.10.31
@Revision1	: 21.02.02
@ETC		: B2
항상 Top이 최신 코드
*/

#define	__BACKJOON_13458__	1		//21.02.02	//시험 감독

#if __BACKJOON_13458__

#if 1
#include <iostream>
#include <cmath>
using namespace std;

int N;
int R[1000000];
double B;
double C;
long long res;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> R[i];
	cin >> B >> C;

	res = N;

	for (int i = 0; i < N; i++) {
		double tmp = R[i] - B;
		if (tmp >= 0) res += ceil(tmp / C);

	}

	cout << res;


	return 0;
}
#endif

#if 0
#pragma warning(disable:4996)
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cmath>
using namespace std;

int N, B, C;
int* test_room;
int64_t result = 0;


int main() {

	cin >> N;

	test_room = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> test_room[i];
	}

	cin >> B >> C;

	result = 0;
	for (int i = 0; i < N; i++) {
		if (test_room[i] > B) result += ceil((static_cast<double>(test_room[i]) - B) / C) + 1;
		else result += 1;

	}

	cout << result;
	return 0;
}
#endif

#endif
