#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG false
using namespace std;


const int N = 8e2+10;
int n,sz,a[N][N],qs[N][N];
///change into checking whether there exists an integer X that median of that interval is less than or equal to X
///we can check whether X is valid by assigning 1 to value strictly greater than X and 0 otherwise
///median of that interval will equal or less than X if and only if number of value that greater than X is less than or equal to size of right hand( will be explained later )
///ex: n = 9, a = {1, 1, 3, 3, 4, 4, 8, 9, 10, 15} size of right hand = 4<-"(n/2)", if X = 5 then numbers of number that greater than are 4(8, 9, 10, 15) then X = 5 is valid and there will exist median that less than or equal to 5
///ex: n = 4, a = {5, 5, 7, 11} size of right hand = 2<-"(n/2)"
///https://atcoder.jp/contests/abc203/tasks/abc203_d?lang=en

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> sz;
    int WA = sz*sz/2;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    int l = 0, r = 1e9, ans;
    while(l <= r){
        int mid = (l+r)/2;
        bool chk = false;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+(a[i][j] > mid);
                if(i >= sz and j >= sz){
                    if(qs[i][j]-qs[i-sz][j]-qs[i][j-sz]+qs[i-sz][j-sz] <= WA){
                        chk = true;
                    }
                }
            }
        }

        if(chk){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
    return 0;
}
