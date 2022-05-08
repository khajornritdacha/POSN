#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n,ta[N][N][N];
bool chk(int K){
    int cnt[12]={};
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(ta[0][i][j] !=0 and ta[0][i][j] != ta[K][i][j])
                return false;
        }
    }
    for(int i=1; i<=9; i+=3){
        for(int j=1; j<=9; j+=3){
            memset(cnt, 0, sizeof(cnt));
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    cnt[ta[K][i+k][j+l]]++;
                }
            }
            for(int k=1; k<=9; k++){
                if(cnt[k] != 1)
                    return false;
            }
        }
    }
    for(int i=1; i<=9; i++){
        memset(cnt, 0 ,sizeof(cnt));
        for(int j=1; j<=9; j++){
            cnt[ta[K][i][j]]++;
        }
        for(int j=1; j<=9; j++){
            if(cnt[j] != 1)
                return false;
        }
    }
    for(int j=1; j<=9; j++){
        memset(cnt, 0, sizeof(cnt));
        for(int i=1; i<=9; i++){
            cnt[ta[K][i][j]]++;
        }
        for(int i=1; i<=9; i++){
            if(cnt[i] != 1)
                return false;
        }
    }
    return true;
}
main(){
    cin >> n;
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cin >> ta[0][i][j];
        }
    }
    for(int now=1; now<=n; now++){
        for(int i=1; i<=9; i++){
            for(int j=1; j<=9; j++){
                cin >> ta[now][i][j];
            }
        }
        if(chk(now))
            cout << now << "\n";
    }
    cout << "END\n";
}
