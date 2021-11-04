#include <cstdio>

const int MAX_N = 10;

int balls[MAX_N];
bool ans;

void dfs(int x, int l, int r) {
    if (x == 10) return;
    if (!ans) return;
    
    if (balls[x] > l) {
        dfs(x + 1, balls[x], r);
    } else if (balls[x] > r) {
        dfs(x + 1, l, balls[x]);
    } else {
        ans = false;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // init
        ans = true;
        // read
        for (int j = 0; j < MAX_N; j++) scanf("%d", &balls[j]);
        // solve
        dfs(0, 0, 0);
        // print
        if (ans) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
