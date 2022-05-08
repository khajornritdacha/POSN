#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e3+10;
struct ST{
    int id,go,si,br;
};
int n,mxg,mxs,mxb,mxt;
ST co[N];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        ST tmp;
        cin >> tmp.id >> tmp.go >> tmp.si >> tmp.br;
        mxg = max(mxg, tmp.go);
        mxs = max(mxs, tmp.si);
        mxb = max(mxb, tmp.br);
        mxt = max(mxt, tmp.go+tmp.si+tmp.br);
        co[i] = tmp;
        //cout << "MAKE : " << co[i].id << " " << co[i].go << " " << co[i].si << " " << co[i].br << "\n";
        //cout <<
    }
    //cout << "Max : " << mxg << " " << mxs << " " << mxb << " " << mxt << "\n";
    while(true){
        int x;
        cin >> x;
        if(x <= 0){
            cout << "good bye" << endl;
            break;
        }
        if(x == 1001){
            //cout << "MX GOLD : " << mxg << "\n";
            for(int i=1; i<=n; i++){
                //cout << "I : " << co[i].id << " " << co[i].go << " " << co[i].si << " " << co[i].br << "\n";
                if(co[i].go == mxg){
                    cout << co[i].id << " ";
                }
            }
        }else if(x == 1002){
            for(int i=1; i<=n; i++){
                if(co[i].si == mxs){
                    cout << co[i].id << " ";
                }
            }
        }else if(x == 1003){
            for(int i=1; i<=n; i++){
                if(co[i].br == mxb){
                    cout << co[i].id << " ";
                }
            }
        }else if(x == 2000){
            for(int i=1; i<=n; i++){
                if(co[i].go+co[i].si+co[i].br == mxt){
                    cout << co[i].id << " ";
                }
            }
        }else if(x == 3000){
            for(int i=1; i<=n; i++){
                if(co[i].go+co[i].si+co[i].br >= 1){
                    cout << co[i].id << " ";
                }
            }
        }else{
            int cnt = 0;
            for(int i=1; i<=n; i++){
                if(co[i].id == x){
                    cout << co[i].go << " " << co[i].si << " " << co[i].br << " " << co[i].go+co[i].si+co[i].br;
                    cnt++;
                }
            }
            if(cnt == 0)
                cout << "invalid code";
        }
        cout << endl;
    }
}
