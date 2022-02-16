/*
@Title		: πÈ¡ÿ
@Name		: ≈È¥œπŸƒ˚
@First0		: 20.11.18
@Revision1	: 21.02.09
@ETC		: S1
«◊ªÛ Top¿Ã √÷Ω≈ ƒ⁄µÂ
*/

#define	__BACKJOON_14891__	1		//21.02.09	//????

#if __BACKJOON_14891__
//1
#if 1
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
#define STRING_SIZE 8

string T[4];
vector<pair<int, int>> List;
int K;
int RESULT;


void RotateClock(std::string& str) {
	char temp = str[7];
	for (int i = STRING_SIZE - 1; i > 0; i--) str[i] = str[i - 1];
	str[0] = temp;
}

void RotateCounterClock(std::string& str) {
	char temp = str[0];
	for (int i = 0; i < STRING_SIZE - 1; i++) str[i] = str[i + 1];
	str[7] = temp;
}

void Sol(int NUM, int WAY, int wave) {

	int counter_way = WAY > 0 ? -1 : 1;

	//øﬁ¬  ≈È¥œπŸƒ˚ »Æ¿Œ
	if (wave > 0 || wave == 0) {
		if (NUM - 1 >= 0 && NUM - 1 < 4) {
			if (T[NUM][6] != T[NUM - 1][2]) Sol(NUM - 1, counter_way, 1);
		}
	}

	//ø¿∏•¬  ≈È¥œπŸƒ˚ »Æ¿Œ
	if (wave < 0 || wave == 0) {
		if (NUM + 1 >= 0 && NUM + 1 < 4) {
			if (T[NUM][2] != T[NUM + 1][6]) Sol(NUM + 1, counter_way, -1);
		}
	}
	WAY > 0 ? RotateClock(T[NUM]) : RotateCounterClock(T[NUM]);
}

int main() {

	for (int i = 0; i < 4; i++) cin >> T[i];
	cin >> K;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		List.push_back(make_pair(a, b));
	}



	for (int i = 0; i < K; i++) Sol(List[i].first - 1, List[i].second, 0);

	if (T[0][0] == '1') RESULT += 1;
	if (T[1][0] == '1') RESULT += 2;
	if (T[2][0] == '1') RESULT += 4;
	if (T[3][0] == '1') RESULT += 8;

	cout << RESULT;

}
#endif

//0
#if 0
#pragma warning(disable:4996)
#include <iostream>

using namespace std;
char gear[4][9];
int K;
int order[100][2];
enum {
	e_ClockWise = 1,
	e_CounterClockWise = -1
};

enum e_State {
	e_Both,
	e_Right,
	e_Left
};

void Rotate_Gear(char* gear, int way);
void Stack_For_Calculate(char(*gear)[9], int position, int way, enum e_State state);

void Stack_For_Calculate(char(*gear)[9], int position, int way, enum e_State state) {
	switch (state)
	{
	case e_Both:
		if (position + 1 <= 3) {
			if (gear[position][2] != gear[position + 1][6])
				Stack_For_Calculate(gear, position + 1, way * -1, e_Right);
		}
		if (position - 1 >= 0) {
			if (gear[position][6] != gear[position - 1][2])
				Stack_For_Calculate(gear, position - 1, way * -1, e_Left);
		}
		break;
	case e_Right:
		if (position + 1 <= 3) {
			if (gear[position][2] != gear[position + 1][6])
				Stack_For_Calculate(gear, position + 1, way * -1, e_Right);
		}
		break;
	case e_Left:
		if (position - 1 >= 0) {
			if (gear[position][6] != gear[position - 1][2])
				Stack_For_Calculate(gear, position - 1, way * -1, e_Left);
		}
		break;
	default:
		break;
	}
	Rotate_Gear((char*)&gear[position], way);

}

void Rotate_Gear(char* gear, int way) {
	char temp;
	switch (way) {
		//Clockwise
	case e_ClockWise:
		temp = gear[7];
		for (int i = 6; i >= 0; i--) {
			gear[i + 1] = gear[i];
		}
		gear[0] = temp;
		break;
	case e_CounterClockWise:
		temp = gear[0];
		for (int i = 1; i < 8; i++) {
			gear[i - 1] = gear[i];
		}
		gear[7] = temp;
		break;
	}
}

int main() {
	//Input
	for (int i = 0; i < 4; i++)
		cin >> gear[i];
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> order[i][0] >> order[i][1];
	}

	//Calculate
	for (int i = 0; i < K; i++) {
		Stack_For_Calculate(gear, order[i][0] - 1, order[i][1], e_Both);
	}

	int result = 0;
	result += gear[0][0] - 48 == 1 ? 1 : 0;
	result += gear[1][0] - 48 == 1 ? 2 : 0;
	result += gear[2][0] - 48 == 1 ? 4 : 0;
	result += gear[3][0] - 48 == 1 ? 8 : 0;
	/*cout << gear[0] << endl;
	cout << gear[1] << endl;
	cout << gear[2] << endl;
	cout << gear[3] << endl;
	cout << "=====================" << endl;*/
	cout << result;

	return 0;
}
#endif
#endif
