//claim : There is a subarray of size 4 that has exactly 2 crewmates and 2 impostors
//proof by contradiction: every subarray of size 4 must have either 1, 3, or 4 impostors then it is false with pegion hole priciples

#include <bits/stdc++.h>
using namespace std;

inline int ask(int a, int b, int c){
    cout << "? " << a << " " << b << " " << c << endl;
    int res; cin >> res;
    assert(res == 0 or res == 1);
    return res;
}

void test_case(){
    int n; cin >> n;
    int pre = -1, im = 0, cr = 0, ans[n+5] = {};
    for(int i = 1; i+2 <= n; i++){
        int res = ask(i, i+1, i+2);
        if(res == 1-pre){
            ans[i+2] = res;
            ans[i-1] = 1-res;
            if(res == 0){
                im = i+2;
                cr = i-1;
            } else {
                cr = i+2;
                im = i-1;
            }
            break;
        }
        pre = res;
    }

    assert(im != 0);

    for(int i = 1; i <= n; i++){
        if(i == im or i == cr) continue;
        int res = ask(i, im, cr);
        ans[i] = res;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += (ans[i] == 0);
    cout << "! " << cnt << " ";
    for(int i = 1; i <= n; i++){
        if(ans[i] == 0) cout << i << " ";
    }
    cout << endl;

    return;
}

int main(void){
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}