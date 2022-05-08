#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG false
using namespace std;


const int N = 8e2+10;
int n,sz,a[N][N],qs[N][N],cnt[N][N],WA;
///https://atcoder.jp/contests/abc203/tasks/abc203_d?lang=en

int chk(int K){
    bool ok = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cnt[i][j] = cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
            qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
            cnt[i][j] += (a[i][j] == K);
            if(a[i][j] < K)
                qs[i][j]++;
            //cout << qs[i][j] << " \n"[j==n];
        }
    }


    for(int i=sz; i<=n; i++){
        for(int j=sz; j<=n; j++){
            int nc = cnt[i][j]-cnt[i-sz][j]-cnt[i][j-sz]+cnt[i-sz][j-sz];
            int ns = qs[i][j]-qs[i-sz][j]-qs[i][j-sz]+qs[i-sz][j-sz];
            if(nc >= 1 and ns+1 <= WA and WA <= ns+nc){
                if(DEBUG){
                    printf("OK %d %d\n", i, j);
                    printf("NS NC : %d %d\n", ns, nc);
                    printf("[%d, %d]\n", ns+1, ns+nc);
                    printf("%d %d %d %d\n", qs[i][j], qs[i-sz][j], qs[i][j-sz], qs[i-sz][j-sz]);
                    printf("\n");
                }
                return 0;
            }
            if(WA <= ns+nc){
                ok = true;
            }
        }
    }
    //cout << "FALSE : " << K << "\n";
    if(ok)
        return -1;
    return 1;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> vec;
    cin >> n >> sz;
    WA = sz*sz/2+(sz%2);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            vec.push_back(a[i][j]);
        }
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end())-vec.begin());
    int l = 0, r = int(vec.size())-1, mid, ans=-1;
    while(l <= r){
        mid = l+(r-l)/2;
        int res = chk(vec[mid]);

        if(DEBUG){
            printf("MID %d %d: %d\n", mid, vec[mid], res);
            printf("-------------------------------\n");
        }

        if(res == 0){
            ans = vec[mid];
            r = mid-1;
        }else if(res == -1){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
    return 0;
}
