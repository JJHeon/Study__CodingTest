/*
@Title		: ����
@Name		: ���
@First0		: 20.11.04
@Revision1	: 21.02.06
@Revision2	: 21.02.06
@ETC		:
�׻� Top�� �ֽ� �ڵ�
*/

#define	__BACKJOON_14501__	1		//21.02.06	//���

#if __BACKJOON_14501__
//2
#if 1
#include <iostream>
#define MAX(A,B) (((A) > (B)) ? (A) : (B))
using namespace std;
int N;
int T[16];
int P[16];
int DP[20];



int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> T[i] >> P[i];

	for (int i = N; i >= 1; i--) {
		if (i + T[i] - 1 > N) {
			DP[i] = DP[i + 1];
			continue;
		}


		DP[i] = MAX(DP[i + T[i]] + P[i], DP[i + 1]);

	}
	cout << DP[1];
	return 0;
}
#endif


//1
#if 0
#include <iostream>
#define MAX(A,B) (((A) > (B)) ? (A) : (B))
using namespace std;

int N;
int T[15];
int P[15];
int RESULT;

int Sol(int nDAY, int PAY) {
	int res = PAY;


	for (int i = nDAY; i < N; i++) {
		if (i + T[i] <= N) res = MAX(res, Sol(i + T[i], PAY + P[i]));
	}

	return res;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> T[i] >> P[i];


	for (int i = 0; i < N; i++) RESULT = MAX(RESULT, Sol(i, 0));

	cout << RESULT;

	return 0;
}
#endif

//0
#if 0
#pragma warning(disable:4996)
#include <iostream>
#include <climits>
using namespace std;

typedef struct {
	int T;
	int P;
} Day_;

int N;
int user_max = INT_MIN;

Day_ calender[16];

void User_Function(int day, int stack_value) {
	if (day > N) { //������ ���� 1�� ������ ���
		user_max = stack_value > user_max ? stack_value : user_max;
		return;
	}
	else if ((day + calender[day].T - 1) > N) {
		user_max = stack_value > user_max ? stack_value : user_max;
		return;
	}
	else {
		stack_value += calender[day].P;
	}

	int further_day = day + calender[day].T;
	int i = further_day;
	//N�� �Ѿ�� ��Ȳ�� ����� ���� ������ �ѹ��� �����ؼ� �����ݽô�.
	do {
		User_Function(i, stack_value);
		i++;
	} while (i <= N);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int T_tmp;
		int P_tmp;
		cin >> T_tmp >> P_tmp;

		calender[i].T = T_tmp;
		calender[i].P = P_tmp;
	}

	for (int i = 1; i <= N; i++) {
		User_Function(i, 0);
	}
	cout << user_max;
	return 0;
}
#endif
#endif
