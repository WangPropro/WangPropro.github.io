#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int f,c;
    cin >> f;
    c = 5 * (f - 32) / 9;
    printf("Celsius = %d", c);
    return 0;
}