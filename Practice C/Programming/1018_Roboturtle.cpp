#include<bits/stdc++.h>
using namespace std;
int n,K,ox=1,oy,nx,ny;
string str;
bool ok = true;
main(){
    cin >>  n;
    for(int i=1; i<=n; i++){
        cin >> str >> K;
        if(str == "BW"){
            ox*=-1;
            oy*=-1;
        }else if(str == "RT"){
            if(ox != 0){
                if(ox == 1)
                    oy = -1;
                else
                    oy = 1;
                ox = 0;
            }else{
                if(oy == 1){
                    ox = 1;
                }else{
                    ox = -1;
                }
                oy = 0;
            }
        }else if(str == "LT"){
            if(ox != 0){
                if(ox == 1)
                    oy = 1;
                else
                    oy = -1;
                ox = 0;
            }else{
                if(oy == 1)
                    ox = -1;
                else
                    ox = 1;
                oy = 0;
            }
        }
        nx += ox*K;
        ny += oy*K;
        if(nx >= 50000 or nx <= -50000 or ny >= 50000 or ny <= -50000)
            ok = false;
    }
    if(!ok)
        cout << "DEAD\n";
    else{
        char ch;
        cout << nx << " " << ny << "\n";
        if(ox == 1)
            ch = 'E';
        else if(ox == -1)
            ch = 'W';
        else if(oy == 1)
            ch = 'N';
        else
            ch = 'S';
        cout << ch;
    }
}
