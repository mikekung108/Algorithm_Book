#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 20;

int n, k, a[MAX_N];

bool dfs(int i, int sum) {
    // when i==n, check whether final result (sum) == k
    if (i==n) return (sum==k);
    // if not use a[i], it means we sum = summ and check next one, hence i+1
    if (dfs(i+1, sum)) return true;
    // if use a[i]
    if (dfs(i+1, sum + a[i])) return true;

    return false;
} 

void solve() {
    if (dfs(0,0)) {
        printf("Yes.\n");
    } else {
        printf("No.\n");
    }
}

void read() {
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);
    printf("a[i]: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
}

int main() {
    read();
    solve();
    return 0;
}
