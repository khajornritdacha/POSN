#include <iostream>
#include <cstring>
#define DEBUG false
using namespace std;

const int N = 410;
using ll = long long;
using pi = pair<int,int>;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int K;
    char str[1010];
    cin >> K >> (str+1);
    int n = strlen(str+1);
    long long ans = 0;
    for(int sz=1; sz<=n; sz++){
        int now = 0;
        for(int i=1,j=1+sz; j<=n; i++,j++){
            if(i > sz)
                now -= (str[i-sz] != str[j-sz]);
            now += (str[i] != str[j]);
            if(i >= sz)
                ans += (now <= K);
        }
    }
    cout << ans << "\n";
    return 0;
}
