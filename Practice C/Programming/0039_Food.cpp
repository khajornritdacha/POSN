#include<bits/stdc++.h>
using namespace std;
int n,m,a[15],ans[100],visit[100],y;
void func(int x){
    if(x==n+1){
        for(int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(x==1&&a[i]!=0){
            continue;
        }
            //cout << a[i-1] << " = " << i << endl;
        if(visit[i]!=1){
        ans[x] = i;
        visit[i] = 1;
        func(x+1);
        visit[i] = 0;
       }
    }
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> y;
        a[y] = y;
    }
    func(1);
    return 0;
}
