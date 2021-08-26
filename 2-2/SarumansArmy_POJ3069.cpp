#include <cstdio>
#include <algorithm>

const int MAX_N = 1000;

int R = 0, N = 0;
int X[MAX_N];

void solve() {
    std::sort(X, X + N);
    int i = 0, ans = 0;

    while (i < N) {
        // start point
        int s = X[i++];
        // if in the range i++
        while ((i < N) && (X[i] <= s + R)) i++;
        // p is adding point
        int p = X[i - 1];
        while ((i < N) && (X[i] <= p + R)) i++;

        ans++;
    }
    printf("%d\n", ans);
}

void read() {
    while (scanf("%d %d", &R, &N)) {
        if ((R == -1) && (N == -1)) break;

        for (int i = 0; i < N; i++)
            scanf("%d", &X[i]);

        solve();
    }
}

int main() {
    read();
    return 0;
}
