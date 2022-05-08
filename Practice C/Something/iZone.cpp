#include<bits/stdc++.h>
using namespace std;
set<int> R,G,B;
int a[1000005],N,M;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        if(i%3==1){
            a[i] = 1;
            R.insert(i);
        }else if(i%3==2){
            a[i] = 2;
            G.insert(i);
        }else{
            a[i] = 3;
            B.insert(i);
        }
    }
    for(int i=0;i<M;i++){
        /*for(auto it=R.begin();it!=R.end();it++){
            cout << *it << " ";
        }
        cout << "\n";*/
        /*for(int j=1;j<=N;j++){
            cout << a[j] << " ";
        }
        cout << "\n";*/
        int code;
        cin >> code;
        if(code==1){
            int id;
            char c;
            cin >> id >> c;
            if(a[id]==1){
                R.erase(id);
            }else if(a[id]==2){
                G.erase(id);
            }else if(a[id]==3){
                B.erase(id);
            }
            if(c=='R'){
                a[id] = 1;
                R.insert(id);
            }else if(c=='G'){
                a[id] = 2;
                G.insert(id);
            }else if(c=='B'){
                a[id] = 3;
                B.insert(id);
            }
        }else{
            int x,y,cntr=0,cntg=0,cntb=0;
            cin >> x >> y;
            auto k =  R.lower_bound(x);
            //cout << *k;
            if(*k<=y&&k!=R.end()){
                //auto it = R.find(k);
                for(auto it = k;it!=R.end();it++){
                    if(*it>y)
                        break;
                    cntr++;
                }
            }
            auto g = G.lower_bound(x);
            if(*g<=y&&g!=G.end()){
                //auto it = G.find(k);
                for(auto it = g;it!=G.end();it++){
                    if(*it>y)
                        break;
                    cntg++;
                    //cout << *it<< " " << cntg << " ";
                }
            }
            auto b = B.lower_bound(x);
            if(*b<=y&&b!=B.end()){
                //auto it = B.find(k);
                for(auto it = b;it!=B.end();it++){
                    if(*it>y)
                        break;
                    cntb++;
                }
                if(cntr>cntg&&cntr>cntb){
                    cout << "R\n";
                }else if(cntg>cntr&&cntg>cntb){
                    cout << "G\n";
                }else if(cntb>cntr&&cntb>cntg){
                    cout << "B\n";
                }else{
                    cout << "None\n";
                }
            }
        }
    }
}
