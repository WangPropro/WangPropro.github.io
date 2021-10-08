#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    char str[1005];
    char count[10] = {};
    scanf("%s", str);
    int length = strlen(str);
    for(int i = 0; i < length; i ++) {
        count[str[i] - '0'] ++;
    }
    for(int i = 0; i < 10; i ++) {
        if(count[i]!= 0) {
            printf("%d:%d\n", i, count[i]);
        }
    }
}