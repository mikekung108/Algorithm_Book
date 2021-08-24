#include <cstdio>
#include <algorithm>
#include <utility>

const int MAX_N = 100000;
int n;
int s[MAX_N], t[MAX_N];
std::pair<int, int> itv[MAX_N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
}

void solve() {
    // because we want to terminal time to select jobs, put t[i] in first
    for (int i = 0; i < n; i++) {
        itv[i].first = t[i];
        itv[i].second = s[i];
    }
    std::sort(itv, itv + n);

    int ans = 0;
    int tt = 0;
    for (int i = 0; i < n; i++) {
        if (itv[i].second >= tt) {
            ans++;
            tt = itv[i].first;
        }
    }
    printf("%d\n", ans);
}

int main() {
    read();
    solve();
    return 0;
}
