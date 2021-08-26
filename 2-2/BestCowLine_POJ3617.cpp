#include <cstdio>
#include <iostream>

const int MAX_N = 2000;
int N;
char S[MAX_N + 1];

void read() {
    scanf("%d\n", &N);
    for (int i = 0; i < N - 1; i++)
        scanf("%c\n", &S[i]);
    scanf("%c", &S[N - 1]);         // last one does not need \n
}

// read2 is faster about 2 times than read, analyzed by POJ
void read2() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        getchar();
        S[i] = getchar();
    }
}

void solve() {
    int a = 0, b = N - 1;
    int ii = 0;
    while (a <= b) {
        ii++;
        bool bFirst = true;
        int max_i = (b - a) / 2;
        for (int i = 0; i <= max_i; i++) {
            if (S[a + i] < S[b - i]) {
                bFirst = true;
                break;
            } else if (S[a + i] > S[b - i]) {
                bFirst = false;
                break;
            }
        }
        // take char
        if (bFirst)
            putchar(S[a++]);
        else 
            putchar(S[b--]);
        if (ii == 80) {
            putchar('\n');
            ii = 0;
        }
    }
    putchar('\n');
}

int main() {
    read2();
    solve();
    return 0;
}
