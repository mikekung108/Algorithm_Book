#include <iostream>

using namespace std;

const int MAX_N = 1000;
int memo[MAX_N];

int fib(int n) {
    if (n<=1) {
        return n;
    } else if (memo[n] != 0) {
        return memo[n];
    } else {
        return memo[n] = fib(n-1) + fib(n-2);
    }
}

int main() {
    int N;
    cin >> N;
    //for (int i=1; i<11; i++) 
    //    cout << fib(i) << endl;
    cout << fib(N) << endl;
    return 0;
}
