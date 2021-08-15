#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 50;
const int MAX_M = 1e8;

int n, m, k[MAX_N];
int kk[MAX_N*(MAX_N+1)/2];
bool bfind = false;

void solve1() {
    for (int a=0; a<n; a++) {
        for (int b=0; b<n; b++) {
            for (int c=0; c<n; c++) {
                for (int d=0; d<n; d++) {
                    if (m == k[a]+k[b]+k[c]+k[d]) {
                        bfind = true;
                    }
                }
            }
        }
    }
}

bool binary_search(int x) {
    int l=0, r=n*(n+1)/2;
    
    while (r - l >= 1) {
        int i = (r + l) / 2;
        if (x == kk[i]) {
           return true;
        } else if (x > kk[i]) {
           l = i + 1;
        } else {
           r = i;
        }
    }
    // if not found
    return false;
}

void solve2(){
    // list all kc + kd
    int ii=0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            kk[ii] = k[i] + k[j];
            ii++;
        }
    }
    sort(kk, kk+n);
    // find 
    for (int a=0; a<n; a++) {
        for (int b=0; b<n; b++) {
            if (binary_search(m-k[a]-k[b]))
                bfind = true;
        }
    }
}

void read() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &k[i]);
    }
}

void answer() {
    if (bfind) {
        printf("Yes.\n");
    } else {
        printf("No.\n");
    }
}

int main() {
    read();
    solve2();
    answer();
    return 0;
}
