#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
struct GOOD{
    int id,code,val;
};
GOOD ex[5];
int n,K,sta,se,sa;
main(){
    for(int i=1; i<=3; i++){
        cin >> ex[i].id >> ex[i].code >> ex[i].val;
    }
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        int idx,pr;
        bool ok = false;
        cin >> idx >> pr;
        for(int j=1; j<=3; j++){
            if(idx == ex[j].id){
                if(ex[j].code == 1){
                    sta += ex[j].val;
                }else{
                    pr -= ex[j].val;
                }
                ok = true;
            }
        }
        if(!ok){
            se +=pr;
        }
        sa += pr;
    }
    cout << sa << "\n" << se << "\n" << sta+se/K;
}
