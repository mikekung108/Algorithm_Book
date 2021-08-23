#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>

const int INF = 100000000;
const int MAX_M = 100;

char maze[MAX_M][MAX_M + 1];
int N, M;       // map size
int sx, sy;     // start pos
int gx, gy;     // goal pos

// distance
int dist[MAX_M][MAX_M];
// x, y dir.
int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};

typedef std::pair<int, int> P;

void read() {
    scanf("%d %d\n", &N, &M);
    scanf("%d %d\n", &sx, &sy);
    scanf("%d %d\n", &gx, &gy);
    for (int i = 0; i < N; i++) {
        scanf("%s", maze[i]);
    }
}

int BFS() {
    // Initialize: INF in distance
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = INF;
        }
    }
    dist[sx][sy] = 0;
    // Initialize: queue
    std::queue<P> que;
    que.push(P(sx, sy));

    // all
    while (que.size()) {
        // get pair 
        P p = que.front();
        que.pop();
        // check if arrive goal or not
        if (p.first == gx && p.second == gy) break;
        // neighbor
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && nx < N && ny >=0 && ny < M && maze[nx][ny] != '#' && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[p.first][p.second] + 1;
                que.push(P(nx, ny));
            }
        }
    }
    return dist[gx][gy];
}

int main() {
    read();
    printf("%d\n", BFS());

    return 0;
}
