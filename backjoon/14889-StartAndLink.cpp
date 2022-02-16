/*
@Title		: 백준
@Name		: 스타트와 링크
@First0		: 20.11.17
@Revision1	: 21.02.08
@ETC		: S3
항상 Top이 최신 코드
*/

#define	__BACKJOON_14889__	1		//21.02.08	//스타트와 링크

#if __BACKJOON_14889__

//1
#if 1
#include <iostream>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <vector>
using namespace std;

int RESULT = INT32_MAX;
int N;
int MAP[20][20];

int CHECK[20];

vector<int> L;

void Sol(int I, int cnt) {
	if (cnt == N / 2) {

		int count = 0;
		for (int i = 0; i < N; i++) {
			if (!CHECK[i]) {
				L.push_back(i);
				count++;
			}
		}



		int result_start_team = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int i2 = i + 1; i2 < N / 2; i2++) {
				result_start_team += (MAP[L[i]][L[i2]] + MAP[L[i2]][L[i]]);
			}
		}

		int result_link_team = 0;
		for (int j = N / 2; j < N; j++) {
			for (int j2 = j + 1; j2 < N; j2++) {
				result_link_team += (MAP[L[j]][L[j2]] + MAP[L[j2]][L[j]]);
			}
		}

		for (int i = 0; i < count; i++) L.pop_back();

		RESULT = std::min(abs(result_start_team - result_link_team), RESULT);
		return;
	}

	for (; I < N; I++) {

		if (CHECK[I]) continue;

		CHECK[I] = true;
		L.push_back(I);

		Sol(I + 1, cnt + 1);

		CHECK[I] = false;
		L.pop_back();

	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> MAP[i][j];

	Sol(0, 0);

	cout << RESULT;
}
#endif

//0
#if 0
#pragma warning(disable:4996)
#include <iostream>
#include <climits>
#include <cstdint>

using namespace std;
int N;
int arr[21][21];
int pick_arr[11];
int pick_arr2[11];

int score_of_team_start;
int score_of_team_link;

int result_min = INT_MAX;

int64_t Factorial(int x, int end_value) {
	if (x == end_value) return x;

	return x * Factorial(x - 1, end_value);
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	//Pick Start Team
	for (int i = 1; i <= N / 2; i++) {
		pick_arr[i] = i;
	}


	int64_t user_count = Factorial(N, (N / 2) + 1) / Factorial((N / 2), 1);
	for (int i = 1; i <= user_count; i++) {


		//Pick Link Team
		int tmp = 1;
		for (int j = 1; j <= N / 2; j++) {

			bool is_same = false;
			for (int k = 1; k <= N / 2; k++) {
				if (tmp == pick_arr[k]) {
					is_same = true;
					tmp++;
					break;
				}
			}
			if (!is_same) {
				pick_arr2[j] = tmp++;
			}
			else {
				j--;
				continue;
			}
		}
		//Debug
		/*for (int j = 1; j <= N / 2; j++) {
			cout << pick_arr[j] << " ";
		}
		cout << endl;
		cout << "===============================" << endl;
		for (int j = 1; j <= N / 2; j++) {
			cout << pick_arr2[j] << " ";
		}
		cout << endl;*/

		//Evaluate
		score_of_team_link = 0;
		score_of_team_start = 0;
		for (int j = 1; j < N / 2; j++) {
			for (int k = j + 1; k <= N / 2; k++) {
				score_of_team_start += arr[pick_arr[j]][pick_arr[k]];
				score_of_team_start += arr[pick_arr[k]][pick_arr[j]];

				score_of_team_link += arr[pick_arr2[j]][pick_arr2[k]];
				score_of_team_link += arr[pick_arr2[k]][pick_arr2[j]];
			}
		}

		int temp_value = score_of_team_start > score_of_team_link ? (score_of_team_start - score_of_team_link) : (score_of_team_link - score_of_team_start);
		result_min = temp_value < result_min ? temp_value : result_min;

		//Change Start Team
		for (int target = N / 2; target > 0; target--) {
			if (pick_arr[target] + 1 > N || pick_arr[target] == (N - (N / 2 - target))) {
				continue;
			}
			else {

				pick_arr[target] += 1;
				int criteria_value = pick_arr[target];
				for (int k = target + 1; k <= N / 2; k++) {
					criteria_value += 1;
					pick_arr[k] = criteria_value;
				}

				break;
			}
		}

	}
	cout << result_min;
	return 0;
}
#endif
#endif
