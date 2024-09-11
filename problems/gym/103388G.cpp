#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

bool findWorkoutSequence(ll N, string &result) {
    vector<ll> fib = {1, 2}; // fib[0] = f(1) = 1, fib[1] = f(2) = 2
    
    // Generate Fibonacci sequence until it exceeds N
    while (fib.back() < N) {
        fib.push_back(fib.back() + fib[fib.size() - 2]);
    }
    
    if (fib.back() != N) return false;
    
    result = "B";
    int index = fib.size() - 1;
    
    while (index > 0) {
        if (N > fib[index - 1]) {
            result = "AB" + result;
            N -= fib[index - 1];
            index -= 2;
        } else {
            result = "B" + result;
            index -= 1;
        }
    }
    
    return true;
}

int main() {
    ll N;
    cin >> N;
    
    string result;
    if (findWorkoutSequence(N, result)) {
        cout << result << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}

