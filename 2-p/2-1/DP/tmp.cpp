#include<cstdio>
#include<cstring>
int pic[25][25];
int ans, n, m;
const int dir[4][2] = {0, -1, 0, 1, 1, 0, -1, 0};
int limit(int x, int y)
{
    return (x>0&&x<=n&&y>0&&y<=m);
}

void dfs(int x, int y, int step)
{
    if(step>=10) return;
    for(int i=0; i<4; i++)
    {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(limit(nx, ny)&&pic[nx][ny]!=1)
        {
            while(limit(nx, ny)&&pic[nx][ny]!=1&&pic[nx][ny]!=3)
            {
                nx +=dir[i][0];
                ny += dir[i][1];
            }
            if(pic[nx][ny]==3)
            {
                if(ans>step+1)
                ans = step+1;
                return;
            }
            else if(pic[nx][ny]==1)
            {
                pic[nx][ny] = 0;
                dfs(nx-dir[i][0], ny-dir[i][1], step+1);
                pic[nx][ny] = 1;
            }
        }
    }
}

int main()
{
    int x, y;
    while(scanf("%d%d", &m, &n), n||m)
    {
        memset(pic, 0, sizeof(pic));
        for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            scanf("%d", &pic[i][j]);
            if(pic[i][j]==2)
            {
                x = i;
                y = j;
            }
        }
        ans = 0x7fff;
        dfs(x, y, 0);
        if(ans>10)
        printf("-1\n");
        else 
        printf("%d\n", ans);
    }
    return 0;
}
