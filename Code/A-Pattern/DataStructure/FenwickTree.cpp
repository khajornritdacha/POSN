#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],n,q;
void up(int i,int val){
    while(i<=n){
        b[i]+=val;
        i+=(i&-i);
    }
}
int rqs(int i){
    int ans=0;
    while(i>0){
        ans+=b[i];
        i-=(i&-i);
    }
    return ans;
}
int qs(int j,int i){
    int mn=min(i,j),mx=max(i,j);
    return rqs(mx)-rqs(mn-1);
}
main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        up(i,a[i]);
    }
    ///print check
    for(int i=1;i<=n;i++)
        cout << b[i] << " ";
    cout << "\n";
    for(int i=1;i<=n;i++)
        cout << rqs(i) << " ";
    cout << "\n";
    ///query
    cin >> q;
    while(q--){
        int x,y,c;
        cin >> c;
        cin >> x >> y;
        if(c==1)
            up(x,y-a[x]),a[x]=y;
        else
            cout << qs(x,y) << "\n";
        cout << "NOW: ";
        for(int i=1;i<=n;i++)
            cout << a[i] << " ";
        cout << "\n";
        cout << "QS: ";
        for(int i=1;i<=n;i++)
            cout << rqs(i) << " ";
        cout << "\n";
    }
}
/*
5
1 3 2 6 11
3
2 3 5
1 3 -5
2 3 5
*/
