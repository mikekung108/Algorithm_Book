#include <cstdio>
#include <algorithm>

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

void solve() {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i + 1][j];
            } else {
            dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }

    printf("%d\n", dp[0][W]);
}

int main() {
    read();
    solve();
    return 0;
}

