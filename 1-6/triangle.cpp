#include <stdio.h>
#include <iostream>
//#include <algorithm>

using namespace std;

const int MAX_N = 100;
const int MAX_A = 1e6;

int n, a[MAX_A];

void solve()
{
    int ans = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            for (int k=j+1; k<n; k++)
            {
                int len = a[i] + a[j] + a[k];
                int ma = max(a[i], max(a[j], a[k]));
                int rest = len-ma;
                if (rest > ma)
                {
                    ans = max(ans, len);
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    n = 5;
    int tmp[] = {2, 3, 4, 5, 10};
    for(int i=0; i<n; i++)
        a[i] = tmp[i];
    solve();

    return 0;
}

