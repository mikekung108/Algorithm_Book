#include <cstdio>
#include <algorithm>

const int MAX_TIMES = 10;
const int MAX_W = 20;
const int MAX_H = 20;
const int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int W, H;
int ans;

int map[MAX_H][MAX_W];

void dfs(int y, int x, int steps) {
    // over boundary
    if (steps > ans) return;

    for (int i = 0; i < 4; i++) {
        int h = y + dir[i][1];
        int w = x + dir[i][0];
        if (map[h][w] == 1) continue;

        while ((h >= 0) && (h < H) && (w >= 0) && (w < W)) {
            switch (map[h][w]) {
                case 0:
                    h += dir[i][1];
                    w += dir[i][0];
                    break;
                case 1:         
                    map[h][w] = 0;
                    dfs(h - dir[i][1], w - dir[i][0], steps+1);
                    map[h][w] = 1;
                    h = -1;
                    break;
                case 3:
                    ans = std::min(ans, steps + 1);
                    return;
                default:
                    break;
            }
        }
    }
}

int main() {
    int s[2];
    while ((scanf("%d %d", &W, &H) != EOF) && (W+H)) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%d", &map[i][j]);
                if (map[i][j] == 2) {
                    s[0] = i;
                    s[1] = j;
                    map[i][j] = 0;
                }
            }
        }
        
        ans = MAX_TIMES + 1;
        dfs(s[0], s[1], 0);
        ans = (ans > 10) ? -1 : ans;
        printf("%d\n", ans);
    }
    return 0;
}
