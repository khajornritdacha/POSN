#include <iostream>
using namespace std;

int main(void){
    int n, sum_odd = 0, sum_even = 0, cnt = 1;
    while(cin >> n){
        if(n == 0) break;
        if(cnt % 2 == 0){
            sum_even += n;
        } else {
            sum_odd += n;
        }
        cnt++;
    }
    
    cout << sum_even << " " << sum_odd << "\n";

    return 0;
}