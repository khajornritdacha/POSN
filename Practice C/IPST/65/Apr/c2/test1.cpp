#include <bits/stdc++.h>
using namespace std;

int get_log(int C, int a) {
    int res = 0;
    while (C > 1) {
        C /= a;
        res++;
    }
    return res;
}

int main(void) {
    cout << get_log(7, 2);
    return 0;
}