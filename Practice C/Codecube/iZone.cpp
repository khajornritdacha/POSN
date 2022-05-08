#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],b[3][N],n,m;
int qs(int i,int cd){
    int ans=0;
    while(i>0){
        ans+=b[cd][i];
        i-=(i&-i);
    }
    return ans;
}
void up(int i,int cd,int val){
    while(i<=n){
        b[cd][i]+=val;
        i+=(i&-i);
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        a[i]=i%3;
    }
    for(int j=1;j<=n;j++){
            int po=j;
            while(po<=n){
                b[j%3][po]+=1;
                po+=(po&-po);
            }
    }
    /*for(int i=1;i<=n;i++) cout << b[1][i] << " ";
    cout << '\n';*/
   /* cout << qs(3,1) << "\n";
    cout << qs(n,1) << " " << qs(n,2) << " " << qs(n,0) << "\n";*/
    while(m--){
        int c;
        cin >> c;
        if(c==1){
            int x;
            char ch;
            cin >> x >> ch;
            up(x,a[x],-1);
            if(ch=='R') a[x]=1;
            else if(ch=='G') a[x]=2;
            else a[x]=0;
            up(x,a[x],1);
        }else{
            int x,y;
            cin >> x >> y;
            int R=qs(y,1)-qs(x-1,1);
            int G=qs(y,2)-qs(x-1,2);
            int B=qs(y,0)-qs(x-1,0);
            //cout << "R=" << R << " "  << "G=" << G << " " << "B=" << B << "\n";
            if(R>G&&R>B) cout << "R\n";
            else if(G>R&&G>B) cout << "G\n";
            else if(B>R&&B>G) cout << "B\n";
            else cout << "None\n";
        }
        //cout << qs(n,1) << " " << qs(n,2) << " " << qs(n,0) << "\n\n";
    }
}
