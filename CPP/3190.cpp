/*
@Title		: 백준
@Name		: 뱀
@First0		: 20.10.22
@Revision1	: 21.01.06
@ETC		: G5
항상 Top이 최신 코드
*/

#include "Manager.h"

#if __BACKJOON_3190__
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
int N, K, L;

int SEC;

queue<pair<int, int>> snake;
vector<pair<int, char>> dirct_list;

int pin_list;
int current_dirct = 0;

int x_way[4] = { 0,-1,0,1 };
int y_way[4] = { 1, 0, -1,0 };

int pos_x = 1;
int pos_y = 1;



int main(int argc, char** argv) {

	cin >> N;
	cin >> K;

	int tmp_x, tmp_y;
	for (int i = 0; i < K; i++) {
		cin >> tmp_x >> tmp_y;
		map[tmp_x][tmp_y] = 1;
	}

	cin >> L;
	int tmp2_s;
	char tmp2_d;
	for (int i = 0; i < L; i++) {
		cin >> tmp2_s >> tmp2_d;
		dirct_list.push_back(make_pair(tmp2_s, tmp2_d));
	}
	// --

	snake.push(make_pair(1, 1));
	// --

	while (true) {
		SEC++;

		pos_x = snake.back().first;
		pos_y = snake.back().second;

		pos_x += x_way[current_dirct];
		pos_y += y_way[current_dirct];

		if (pos_x<1 || pos_x>N || pos_y < 1 || pos_y > N) break;
		if (map[pos_x][pos_y] == 2) break;

		snake.push(make_pair(pos_x, pos_y));

		if (map[pos_x][pos_y] != 1) {
			pair<int, int> del_pos = snake.front();
			map[del_pos.first][del_pos.second] = 0;
			snake.pop();
		}
		map[pos_x][pos_y] = 2;

		if (dirct_list.size() > pin_list) {
			if (dirct_list[pin_list].first == SEC) {
				switch (dirct_list[pin_list].second) {
				case 'L':
					current_dirct = (current_dirct + 1) % 4;
					break;
				case 'D':
					current_dirct = (current_dirct + 3) % 4;
					break;
				}

				pin_list++;
			}
		}

	}
	cout << SEC;
}

//0 - First
#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
int N, K, L;

int SEC;

queue<pair<int, int>> snake;
vector<pair<int, char>> dirct_list;

int pin_list;
int current_dirct = 0;

int x_way[4] = { 0,-1,0,1 };
int y_way[4] = { 1, 0, -1,0 };

int pos_x = 1;
int pos_y = 1;



int main(int argc, char** argv) {

	cin >> N;
	cin >> K;

	int tmp_x, tmp_y;
	for (int i = 0; i < K; i++) {
		cin >> tmp_x >> tmp_y;
		map[tmp_x][tmp_y] = 1;
	}

	cin >> L;
	int tmp2_s;
	char tmp2_d;
	for (int i = 0; i < L; i++) {
		cin >> tmp2_s >> tmp2_d;
		dirct_list.push_back(make_pair(tmp2_s, tmp2_d));
	}
	// --

	snake.push(make_pair(1, 1));
	// --

	while (true) {
		SEC++;

		pos_x = snake.back().first;
		pos_y = snake.back().second;

		pos_x += x_way[current_dirct];
		pos_y += y_way[current_dirct];

		if (pos_x<1 || pos_x>N || pos_y < 1 || pos_y > N) break;
		if (map[pos_x][pos_y] == 2) break;

		snake.push(make_pair(pos_x, pos_y));

		if (map[pos_x][pos_y] != 1) {
			pair<int, int> del_pos = snake.front();
			map[del_pos.first][del_pos.second] = 0;
			snake.pop();
		}
		map[pos_x][pos_y] = 2;

		if (dirct_list.size() > pin_list) {
			if (dirct_list[pin_list].first == SEC) {
				switch (dirct_list[pin_list].second) {
				case 'L':
					current_dirct = (current_dirct + 1) % 4;
					break;
				case 'D':
					current_dirct = (current_dirct + 3) % 4;
					break;
				}

				pin_list++;
			}
		}

	}
	cout << SEC;
}
#endif

#endif
