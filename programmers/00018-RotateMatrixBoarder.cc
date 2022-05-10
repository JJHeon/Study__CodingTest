#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void Function(vector<int>& answer, vector<vector<int>>& matrix, int i1, int j1, int i2, int j2) {
    int first_spot;
    int minimum_value;
    int previous_i1 = i1;
    int previous_j1 = j1;
    first_spot = minimum_value = matrix[i1][j1];

    for (; i1 < i2; ++i1) {
        matrix[i1][j1] = matrix[i1 + 1][j1];
        minimum_value = min(minimum_value, matrix[i1][j1]);
    }

    for (; j1 < j2; ++j1) {
        matrix[i1][j1] = matrix[i1][j1 + 1];
        minimum_value = min(minimum_value, matrix[i1][j1]);
    }

    for (; i1 > previous_i1; --i1) {
        matrix[i1][j1] = matrix[i1 - 1][j1];
        minimum_value = min(minimum_value, matrix[i1][j1]);
    }

    for (; j1 > previous_j1 + 1; --j1) {
        matrix[i1][j1] = matrix[i1][j1 - 1];
        minimum_value = min(minimum_value, matrix[i1][j1]);
    }

    matrix[i1][j1] = first_spot;
    answer.push_back(minimum_value);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));

    int count = 1;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j) matrix[i][j] = count++;

    for (auto querie : queries) {
        int x1 = querie[0] - 1;
        int y1 = querie[1] - 1;
        int x2 = querie[2] - 1;
        int y2 = querie[3] - 1;

        Function(answer, matrix, x1, y1, x2, y2);
    }

    return answer;
}