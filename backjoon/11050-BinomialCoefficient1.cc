#include <iostream>
#include <vector>

using namespace std;

int factorial(int value, int count){
    if (count == 0) return 1;
    return factorial(value - 1, count - 1) * value;
}

int main(){
    int n, k;
    cin >> n >> k;

    cout << factorial(n, k) / factorial(k, k) << endl;

    return 0;
}