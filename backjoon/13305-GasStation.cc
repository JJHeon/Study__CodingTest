#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int N;
vector<int> HIGHWAY_COST;
vector<int> GAS_STATION;
unsigned long long RESULT;

int main() {
    cin >> N;
    HIGHWAY_COST.resize(N - 1);
    for (auto& way : HIGHWAY_COST) cin >> way;

    GAS_STATION.resize(N);
    for (auto& station : GAS_STATION) cin >> station;

    // int endPos = GAS_STATION.size() - 1;
    // while(endPos != 0){
    // 	//Search Min Value
    // 	int minPos = 0;
    // 	long long minValue = INT32_MAX;
    // 	for(auto i = 0; i != endPos; ++i) {
    // 		if(minValue > GAS_STATION[i]){
    // 			minValue = GAS_STATION[i];
    // 			minPos = i;
    // 		}
    // 	}

    // 	//Calulate from MinPos to end()
    // 	for(int i = minPos; i != endPos; ++i){
    // 		RESULT += (long long)minValue * HIGHWAY_COST[i]);
    // 	}
    // 	endPos = minPos;
    // }
    int minValue = GAS_STATION[0];
    for (auto i = 0; i < GAS_STATION.size() - 1; ++i) {
        minValue = minValue < GAS_STATION[i] ? minValue : GAS_STATION[i];
        RESULT += (unsigned long long)minValue * HIGHWAY_COST[i];
    }
    cout << RESULT;
    return 0;
}