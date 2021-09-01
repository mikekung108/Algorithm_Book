#include <cstdio>
#include <algorithm>
#include <cstring>

const int MAX_N = 100;
const int MAX_W = 10000;
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];

void read() {
    scanf("%d %d", &n, &W);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
}

int rec(int i, int j) {
    // if it has been calculated once, then take the recorded value.
    if (dp[i][j] >= 0) {
        return dp[i][j];
    }
    
    // same as before
    int res = 0;
    if (i == n) {
        res = 0;
    } else if (j < w[i]) {
        res = rec(i + 1, j);
    } else {
        res = std::max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }

    return dp[i][j] = res;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, W));
}

int main() {
    read();
    solve();
    return 0;
}

