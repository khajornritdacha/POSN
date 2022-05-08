#include "cheat.h"
#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
int pa[N],wei,wa[N];
bool ini;

int fi(int x){
    while(pa[x] > 0)
        x = pa[x];
    return x;
}

void uni(int p1, int p2, int w){
    int h1 = fi(p1), h2 = fi(p2);
    if(h1 == h2) return;
    if(pa[h1] > pa[h2]) swap(h1, h2);
    pa[h1] += pa[h2];
    wa[h2] = w;
    pa[h2] = h1;
    return;
}

void init(){
    for(int i=1; i<=2e5; i++){
        pa[i] = -1;
    }
}

void cheat(int p1, int p2){
    if(!ini){ ini = true, init();}

    uni(p1, p2, ++wei);
    /*if(DEBUG){
        cout << "NOW : " << p1 << " " << p2 << "\n";
        cout << "PA : ";
        for(int i=1; i<=4; i++){
            cout << pa[i] << " ";
        }
        cout << pa[100] << " ";
        cout << "\n";
        cout << "WA : ";
        for(int i=1; i<=4; i++){
            cout << wa[i] << " ";
        }
        cout << wa[100] << " ";
        cout << "\n";
        cout << "----------------------\n";
    }*/


}

int investigate(int p1, int p2){
    int h1 = fi(p1), h2 = fi(p2);
    if(h1 != h2){
        return -1;
    }

    if(DEBUG){
        cout << "Inves : " << p1 << " " << p2 << "\n";
    }

    int l=1, r=wei, ans = -1;
    while(l <= r){
        int mid = (l+r)/2, t1 = p1, t2 = p2;
        while(pa[t1] > 0 and wa[t1] <= mid) t1 = pa[t1];
        while(pa[t2] > 0 and wa[t2] <= mid) t2 = pa[t2];
        //cout << "MID : " << mid << " " << t1 << " " << t2 << "\n";
        if(t1 == t2){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    //cout << "---------------\n";
    return ans;
}
