#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NUM 1000000

int times, length, ants;
int pos[MAX_NUM];
    
int main(){
    scanf("%d", &times);
    for(int i=0; i<times; i++){
        int minT=0;
        int maxT=0;
        scanf("%d %d", &length, &ants);
        for(int i=0; i<ants; i++){
            scanf("%d", &pos[i]);
            minT = max(minT, min(pos[i], length-pos[i]));
            maxT = max(maxT, max(pos[i], length-pos[i]));
        }
        printf("%d %d\n", minT, maxT);
    }
    return 0;
}
