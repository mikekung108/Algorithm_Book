#include <cstdio>
#include <utility>

const int MAX_N = 20000;

int N, L[MAX_N];

void read() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }
}

void solve() {
    long long ans = 0;

    while (N > 1) {
        int mini1 = 0, mini2 = 1;
        if (L[mini1] > L[mini2]) std::swap(mini1, mini2);
        // find the shortest and 2nd shortest
        for (int i = 2; i < N; i++) {
            if (L[i] < L[mini1]) {
                mini2 = mini1;
                mini1 = i;
            } else if (L[i] < L[mini2]) {
                mini2 = i;
            }
        }

        int t = L[mini1] + L[mini2];
        ans += t;

        if (mini1 == N-1) std::swap(mini1, mini2);
        L[mini1] = t;
        L[mini2] = L[N-1];
        N--;
    }
    printf("%lld\n", ans);
}

int main() {
    read();
    solve();
    return 0;
}
