#include <cstdio>
#include <limits>
#include <algorithm>

const int INF = 1e9 + 1;

const int MAX_N = 100;
const int MAX_V = 100;
const int MAX_NV1 = MAX_N * MAX_V + 1;

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_NV1];

void read() {
    scanf("%d %d", &n, &W);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
}

void solve() {
    // initialize
    std::fill(dp[0], dp[0] + MAX_NV1, 1e9);
    dp[0][0] = 0;

    // compute
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= MAX_NV1 - 1; j++) {
            if (j < v[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = std::min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }

    // find the answer
    int res = 0;
    for (int i = 0; i <= MAX_NV1 - 1; i++) {
        if (dp[n][i] <= W)
            res = i;
    }

    //print answer
    printf("%d\n", res);

    //for (int i = 0; i <= n; i++) {
    //    for (int j = 0; j <= 16; j++) {
    //        printf("%3.d ", dp[i][j]);
    //    }
    //    printf("\n");
    //}
}

int main() {
    read();
    solve();
    return 0;
}
