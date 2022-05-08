#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int base,Q,lg[N],lim = 1e6;

int met1(int x){
    int lg = 0;
    while(x/base >= 1){ ///time base 2 sides it will become x >= base (save more time)
        x /= base;
        lg++;
    }
    return lg;
}

int met2(int x){ ///Only works for log2
    int lg = 0;
    while(1<<(lg+1) <= x) lg++;
    return lg;
}

int met3(int x){ ///Pre-compute take O(N) and Answering query takes O(1)
    return lg[x];
}

int main(void){

    cin >> Q >> base; ///Input number of query and base of Log

    for(int i = base; i <= lim; i++){
        lg[i] = lg[i/base]+1;
    }

    while(Q--){
        int x; cin >> x;
        cout << met1(x) << "\n";
        cout << met2(x) << "\n";
        cout << met3(x) << "\n";
    }

    return 0;
}
