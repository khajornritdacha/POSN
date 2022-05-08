#include<bits/stdc++.h>
using namespace std;
int n,aw,bw,pp[105];
void gen(int lv,int lea,int leb,int cnt){
    pp[lv] = 1;
    if(lea+1<n){
        gen(lv+1,lea+1,leb,cnt+1);
    }else{
        for(int i=1;i<=cnt;i++){
            if(pp[i]==1){
                cout << "W ";
            }else{
                cout << "L ";
            }
        }
        cout << "\n";
    }
    pp[lv] = 2;
    if(leb+1<n){
        gen(lv+1,lea,leb+1,cnt+1);
    }else{
        for(int i=1;i<=cnt;i++){
            if(pp[i]==1){
                cout << "W ";
            }else{
                cout << "L ";
            }
        }
        cout << "\n";
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> aw >> bw;
    gen(1,aw,bw,1);
}
