#include <bits/stdc++.h>
using namespace std;

void TOH(int disc, int st, int aux, int ed){
    if(disc <= 0) return;
    TOH(disc-1, st, ed, aux); ///move n-1 disc to auxiliary rod
    cout << st << " " << ed << "\n"; ///move n-th disc from st rod to ed rod
    TOH(disc-1, aux, st, ed); ///solve for n-1 disc but its start rod changed to aux rod
    return;
}

int main(void){
    int n;
    cin >> n;
    cout << (1<<n)-1 << "\n";
    TOH(n, 1, 2, 3);
    return 0;
}
