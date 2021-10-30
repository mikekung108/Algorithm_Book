#include <cstdio>

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

const int MAX_W = 20;
const int MAX_H = 20;

char tiles[MAX_H][MAX_W + 1];

int H, W;

int count = 0;

void dfs(int x, int y) {
    // initialize
    tiles[x][y] = '#';

    // count
    count++;

    // dfs
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ((nx >= 0) && (nx < H) && (ny >= 0) && (ny < W) && (tiles[nx][ny] == '.')) {
            dfs(nx, ny);
        }
    }
}

void solve() {
    int sx, sy;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (tiles[i][j] == '@') {
                sx = i;
                sy = j;
                break;
            }
        }
    }
    dfs(sx, sy);
    printf("%d\n", count);
}

int main() {
    while ((scanf("%d %d", &W, &H) != EOF) && (W + H)) {
        for (int i = 0; i < H; i++) {
            scanf("%s", tiles[i]);
        }
        solve();
        count = 0;
    }
    return 0;
}
