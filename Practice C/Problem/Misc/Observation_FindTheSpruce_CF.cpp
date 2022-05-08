#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
int t,r,c,lv[510][510];
char a[510][510];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        long long ans=0;
        cin >> r >> c;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                cin >> a[i][j];
                if(a[i][j]=='*'){
                   lv[i][j]=1;
                    ans++;
                }
            }
        }
        vector<pair<int,int>> lvup;
        for(int k=2; k<=r; k++){
            for(int i=k; i<=r; i++){
                for(int j=1; j<=c; j++){
                    if(a[i][j]!='*') continue;
                    if(lv[i-1][j]==k-1&&lv[i][j-1]==k-1&&lv[i][j+1]==k-1){
                        lvup.emplace_back(i,j);
                        ans++;
                    }
                }
            }
            if(DEBUG){
                cout << "LV: " << k << "\n";
            }
            for(auto [x,y] : lvup){
                lv[x][y]=k;
                if(DEBUG){
                    cout << x << " " << y << "\n";
                }
            }
            lvup.clear();
        }
        cout << ans << "\n";
        for(int i=1; i<=r; i++) for(int j=1; j<=c; j++) lv[i][j]=0;
    }
}

/*
https://codeforces.com/problemset/problem/1461/B
*/
