#include <cstdio>

const int MAX_H = 100;
const int MAX_W = 100;

int h, w;
int ans;
char kind;

int dxy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

char map[MAX_H][MAX_W + 1];

void dfs(int y, int x) {
    map[y][x] = '.';

    for (int i = 0; i < 4; i++) {
        int y2 = y + dxy[i][1];
        int x2 = x + dxy[i][0];
        if ((x2 >= 0) && (x2 < w) && (y2 >= 0) && (y2 < h) && map[y2][x2] == kind) {
            dfs(y2, x2);
        }
    }
}

void solve() {
    ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] != '.') {
                kind = map[i][j];
                dfs(i, j);
                ans++;
            }
        }
    }
}

int main() {
    while ((scanf("%d %d", &h, &w) != EOF) && (h + w)) {
        for (int i = 0; i < h; i++) {
            scanf("%s", map[i]);
        }
        // solve
        solve();
        // print
        printf("%d\n", ans);
    }
    return 0;
}
