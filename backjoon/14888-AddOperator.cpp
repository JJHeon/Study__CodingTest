/*
@Title		: ¹??Ø
@Name		: ¿????? ³?¿?³?±?
@First0		: 20.11.10
@Revision1	: 21.02.07
@Revision2	: 21.02.07
@ETC		: S1
?×?? Top?? ??½? ????
*/

#define	__BACKJOON_14888__	1		//21.02.07	//연산자 끼워넣기

#if __BACKJOON_14888__

// 2
#if 1
#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;

int N;
int ARRAY[11];
int OPERATOR[4];

int MAX_RESULT = INT32_MIN;
int MIN_RESULT = INT32_MAX;

void DFS(int res, int cnt) {
    if (cnt == N) {
        MAX_RESULT = std::max(MAX_RESULT, res);
        MIN_RESULT = std::min(MIN_RESULT, res);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (OPERATOR[i] > 0) {
            OPERATOR[i]--;

            if (i == 0)
                DFS(res + ARRAY[cnt], cnt + 1);
            else if (i == 1)
                DFS(res - ARRAY[cnt], cnt + 1);
            else if (i == 2)
                DFS(res * ARRAY[cnt], cnt + 1);
            else if (i == 3)
                DFS(res / ARRAY[cnt], cnt + 1);

            OPERATOR[i]++;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> ARRAY[i];
    for (int i = 0; i < 4; i++) cin >> OPERATOR[i];

    DFS(ARRAY[0], 1);

    cout << MAX_RESULT << endl;
    cout << MIN_RESULT << endl;

    return 0;
}
#endif

// 1
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
//#include <cstring>
using namespace std;

int MAX_RESULT = INT32_MIN;
int MIN_RESULT = INT32_MAX;

int N;
int VALUE[11];
int OPERATOR[11];
bool OPERATOR_MAP[11];

vector<int> LINE;

void CalculateValue(std::vector<int>& Target) {
	int res = VALUE[0];
	for (int i = 1; i < N; i++) {
		switch (OPERATOR[Target[i - 1]])
		{
		case 0:
			res += VALUE[i];
			break;
		case 1:
			res -= VALUE[i];
			break;
		case 2:
			res *= VALUE[i];
			break;
		case 3:
			res /= VALUE[i];
			break;
		}
	}
	MAX_RESULT = std::max(res, MAX_RESULT);
	MIN_RESULT = std::min(res, MIN_RESULT);

	return;
}

void DFS(int cnt) {
	if (cnt == N - 1) {
		CalculateValue(LINE);
		return;
	}

	for (int i = 1; i < N; i++) {
		if (OPERATOR_MAP[i] == true) continue;

		OPERATOR_MAP[i] = true;
		LINE.push_back(i);
		DFS(cnt + 1);
		LINE.pop_back();
		OPERATOR_MAP[i] = false;
	}
}



int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> VALUE[i];

	int tmp;
	int i = 1;
	for (int j = 0; j < 4; j++) {
		cin >> tmp;
		for (int k = 0; k < tmp; k++) {
			OPERATOR[i++] = j;
		}
	}

	DFS(0);

	cout << MAX_RESULT << endl;
	cout << MIN_RESULT;

}
#endif

// 0
#if 0
#pragma warning(disable : 4996)
#include <iostream>
#include <climits>
#include <cstdint>
#include <cmath>
using namespace std;
int N;
int arr[11];
int user_operator_arr[11];
int user_operator_num_counter[11];

int64_t result;
int64_t user_max = INT_MIN;
int64_t user_min = INT_MAX;

enum {
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE
};
int Factorial(int x) {
	if (x > 0) {
		if (x == 1) return 1;

		return x * Factorial(x - 1);
	}
}

//1 ~ N±???
bool Pulse_xUP_Number_Of_Cases(int* cases_array, int size, int pulse_x) {
	int user_max = size;

	if (pulse_x > 0) {
		int target_position = size;


		while (pulse_x != 0) {
			if (target_position < 1) return false; //¸¸¾? 1º¸´? ¹Ø??¸? ³¡³?

			bool is_existent = false;

			//target_position ??¿¡??´?°??ß ³ªº¸´? ??°??? ?¸????³??
			for (int i = target_position + 1; i <= size; i++) {
				if (cases_array[target_position] < cases_array[i]) {
					is_existent = true;
					break;
				}
			}
			//?¸????´? °æ¿?.
			if (is_existent) {

				bool is_continue = true;
				int futher_value = cases_array[target_position];

				while (futher_value <= size && is_continue) {
					futher_value++;
					is_continue = false;

					//±??Ø?¡ ¾?¿¡??´? ¾???°? ???¡??³??
					for (int i = 1; i < target_position; i++) {
						if (futher_value == cases_array[i]) {
							is_continue = true;
						}
					}

					//???¡???? ¾??½ ok
					if (!is_continue) {
						cases_array[target_position] = futher_value;
						pulse_x--;

						//target?º ?¤?m°? , targetÆ÷?? ¾?´? ??±¸???? ??¿???°? ±× ??¾????º 1¿¡¼­ °¡±?¿? ¼ø?¸·? ¹??¡????
						for (int i = target_position + 1; i <= size; i++) {
							for (int j = 1; j <= size; j++) {
								bool is_pass = true;

								//¾?´???¶? º?½???³??
								for (int k = 1; k <= i - 1; k++) {
									if (cases_array[k] == j) {
										is_pass = false;
										break;
									}
								}

								//¾?´?°? ´?¸?´?. ±×·³ ok pass
								if (is_pass) {
									cases_array[i] = j;
									break;
								}

							}
						}
					}

				}
			}
			//?¸?????? ¾?´?´? 
			else {
				target_position--;
			}
		}
	}

	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	int* user_operator = new int[4];
	for (int i = 0; i < 4; i++)
		cin >> user_operator[i];


	int count = 1; //1º??? ????
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < user_operator[i]; j++) {
			user_operator_arr[count++] = i;
		}
	}
	delete[] user_operator;

	//1,2,3,4,5,6,7,8 ... ¼ø ±?º? ¹??¡
	for (int i = 1; i <= N; i++) {
		user_operator_num_counter[i] = i;
	}

	int count2 = Factorial(N - 1);
	for (int i = 1; i <= count2; i++) {

		result = 0;
		result = arr[0];
		for (int i = 1; i < N; i++) {

			switch (user_operator_arr[user_operator_num_counter[i]])
			{
			case PLUS:
				result += arr[i];
				break;
			case MINUS:
				result -= arr[i];
				break;
			case MULTIPLY:
				result *= arr[i];
				break;
			case DIVIDE:
				result /= arr[i];
				break;
			}

		}

		if (Pulse_xUP_Number_Of_Cases(user_operator_num_counter, N - 1, 1));
		user_max = user_max < result ? result : user_max;
		user_min = user_min > result ? result : user_min;
	}
	cout << user_max << endl;
	cout << user_min;


	return 0;
}
#endif
#endif
