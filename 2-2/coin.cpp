#include <cstdio>
#include <iostream>

using namespace std;

const int value[6] = {1, 5, 10, 50, 100, 500};
int Coin[6];
int A;

void read() {
    for (int i = 0; i < 6; i++) {
        scanf("%d", &Coin[i]);
    }
    scanf("%d", &A);
}

void solve() {
    int ans = 0;
    for (int i = 5; i >=0; i--) {
        int t = min(A/value[i], Coin[i]);
        A -= t * value[i];
        ans += t;
    }
    printf("%d\n", ans);
}

int main() {
    read();
    solve();
    return 0;
}
