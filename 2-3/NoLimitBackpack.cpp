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

// O(nW^2)
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= W; j++) {
			for (int k=0; k * w[i] <= j; k++) {
				dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j - k * w[i]] + k * v[i]);
			}
		}
	}
	printf("%d\n", dp[n][W]);
}

// I(nW)
void solve2() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= W; j++) {
			if (j < w[i]) {
				dp[i + 1][j] = dp[i][j];
			} else {
				dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
			}
		}
	}
	printf("%d\n", dp[n][W]);
}
int main() {
	read();
	solve2();
	return 0;
}
