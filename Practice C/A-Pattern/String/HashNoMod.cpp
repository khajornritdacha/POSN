#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
string str;
int h[N],pw[N],mu=1e9+7;

main(){
    cin >> str;
    pw[0] = 1;
    for(int i=1; i<=str.size(); i++){
        h[i] = h[i-1]*mu+str[i-1];
        pw[i] = pw[i-1]*mu;
    }
    int Q;
    cin >> Q;
    while(Q--){
        int l,r;
        cin >> l >> r;
        int tmp = 0;
        for(int i=l; i<=r; i++){
            tmp*=mu;
            tmp += str[i-1];
        }
        int hh = h[r]-h[l-1]*pw[r-l+1]; ///pw[ sizeof(query string (r-l+1)) ]
        printf("-------------\n");
        printf("L R sz: %d %d %d\n", l, r, r-l+1);
        //printf(" : %d %d\n", l, r);
        printf("Real : %d\n", tmp);
        printf("Hash : %d\n", hh);
        if(tmp != hh){
            printf("WARNING!!!!!\n");
        }
        printf("-------------\n");
    }
}
