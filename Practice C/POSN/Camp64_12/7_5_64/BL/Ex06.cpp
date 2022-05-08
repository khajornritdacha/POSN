#include<bits/stdc++.h>
using namespace std;

vector<int> ans,ans2;
int pw[15];
long long sum1,sum2;

void gen(int r, int l, int now = 0, int pre=0){
    //cout << r << " " << l << "\n";
    if(r < l){
        ans.emplace_back(now);
        sum1 += now;
        return;
    }
    for(int i=pre+1; i<=9; i++){
        if(l != r)
            gen(r-1, l+1, now+pw[r]*i+pw[l]*i, i);
        else
            gen(r-1, l+1, now+pw[r]*i, i);
    }
}

void gen2(int r, int l, int now=0, int pre=10){
    //cout << r << " " << l << " " << now << " " << pre << "\n";
    if(r < l){
        ans2.emplace_back(now);
        sum2 += now;
        return;
    }
    for(int i=pre-1; i>=0; i--){
            //cout << "NOW : " << i << "\n";
        if(l != 0 or i!= 0){
            //cout << "GO : " << i << " " << now << " " << now+pw[r]*i << " " << r-1 << " " << l+1 << "\n";
            if(l != r)
                gen2(r-1, l+1, now+pw[r]*i+pw[l]*i, i);
            else
                gen2(r-1, l+1, now+pw[r]*i, i);
        }
    }
}
main(){
    pw[0] = 1;
    for(int i=1; i<=9; i++)
        pw[i] = pw[i-1]*10;

    for(int i=1; i<=8; i++){
        gen(i-1, 0);
    }

    for(int i=1; i<=8; i++){
        gen2(i-1, 0);
    }
    /*sort(ans.begin(), ans.end());
    for(int an : ans)
        cout << an << "\n";*/
    /*sort(ans2.begin(), ans2.end());
    for(int an : ans2){
        cout << an << "\n";
    }*/

    cout << "Number and Sum of ascending Palindromes : " << ans.size() << " " << sum1 << "\n";
    cout << "Number and Sum of descending Palindromes : " << ans2.size() << " " << sum2 << "\n";
}
