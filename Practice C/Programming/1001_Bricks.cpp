#include<bits/stdc++.h>
using namespace std;
char ipt[50][50],ans[50][50];
int r,c,bri[50],n[50];
main(){
    cin >> r >> c;
    for(int i=0;i<c;i++){
        bri[i] = -1;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> ipt[i][j];
            if(ipt[i][j]=='O'&&bri[j]==-1){
                bri[j] = i;
            }
        }
    }
    for(int j=0;j<c;j++){
        cin >> n[j];
    }
    for(int j=0;j<c;j++){
        if(bri[j] == -1){
            for(int i=r-1;i>r-n[j]-1;i--){
                if(i<0)
                    break;
                ipt[i][j] = '#';
            }
        }else{
            int cnt=0;
            for(int i=bri[j]-1;i>=0;i--){
                if(cnt==n[j]||i<0)
                    break;
                cnt++;
                ipt[i][j] = '#';
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << ipt[i][j];
        }

        cout << endl;
    }
}
