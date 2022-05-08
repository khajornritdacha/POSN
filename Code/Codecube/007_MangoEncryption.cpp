#include<bits/stdc++.h>
#define DEBUG true
#define int long long
using namespace std;

string in,ot;
bool ok = true;
vector<int> ans;
//p q r s t u v w
main(){
    cin >> in >> ot;
    if(in.size() != ot.size())
        ok = false;
    for(int i=0; i<in.size(); i++){
        in[i] = toupper(in[i]);
        ot[i] = toupper(ot[i]);
        int res = (in[i]-ot[i]+26)%26;
        //cout << in[i] << " " << ot[i] << " " << res << "\n";
        if(res > 9){
            ok = false;
        }
        ans.emplace_back(res);
    }

    if(ok){
        for(int an : ans)
            cout << an;
    }else{
        cout << "R.I.P.\n";
    }
}
