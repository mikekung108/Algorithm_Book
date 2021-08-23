#include <cstdio>

const int MAX_N = 100;

int N, M;
char field[MAX_N][MAX_N+1];

void dfs(int x, int y) {
    field[x][y] = '.';

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = x + i;
            int ny = y + j;
            if ( nx >= 0 && nx < N && ny >= 0 && ny < M && field[nx][ny] == 'W') {
                dfs(nx, ny);
            }
        }
    }
}

void solve() {
    int res = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (field[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);
}

void read() {
    scanf("%d %d\n", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", field[i]);
    }
}

int main() {
    read();
    solve();
    return 0;
}
