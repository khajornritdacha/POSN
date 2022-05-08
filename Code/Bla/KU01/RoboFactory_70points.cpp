#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int H[2], B[2], X, Y, ans;

int cal1(int Ht[], int Bt[], int &W_full, int &W_half, int cur){
    int full[2] = {};
    full[cur] = min(Ht[cur], Bt[cur]), full[!cur] = min(Ht[!cur], Bt[!cur]);
    //cout << "FULL : " << full[cur] << " " << full[!cur] << "\n";
    int res = 0;
    if(W_full >= full[cur]){
        W_full -= full[cur];
        Ht[cur] -= full[cur];
        Bt[cur] -= full[cur];
        res += full[cur];
        full[cur] = 0;
    }else{
        full[cur] -= W_full;
        Ht[cur] -= W_full;
        Bt[cur] -= W_full;
        res += W_full;
        W_full = 0;
    }
    if(W_full > 0){
        if(W_full >= full[!cur]){
            W_full -= full[!cur];
            Ht[!cur] -= full[!cur];
            Bt[!cur] -= full[!cur];
            res += full[!cur];
            full[!cur] = 0;
        }else{
            full[!cur] -= W_full;
            Ht[!cur] -= W_full;
            Bt[!cur] -= W_full;
            res += W_full;
            W_full = 0;
        }
    }
    //cout << "RES : " << res << "\n";
    return res;
}

int cal2(int Ht[], int Bt[], int &W_full, int &W_half, int cur){
    int C1 = min(Ht[cur], Bt[!cur]), C2 = min(Ht[!cur], Bt[cur]);
    int res = 0;
    if(W_half >= C1){
        W_half -= C1;
        Ht[cur] -= C1;
        Bt[!cur] -= C1;
        res += C1;
        C1 = 0;
    }else{
        C1 -= W_half;
        Ht[cur] -= W_half;
        Bt[!cur] -= W_half;
        res += W_half;
        W_half = 0;
    }
    if(W_half > 0){
        if(W_half >= C2){
            W_half -= C2;
            Ht[!cur] -= C2;
            Bt[cur] -= C2;
            res += C2;
            C2 = 0;
        }else{
            C2 -= W_half;
            Ht[!cur] -= W_half;
            Bt[cur] -= W_half;
            res += W_half;
            W_half = 0;
        }
    }
    return res;
}

int main(void){
    cin >> H[0] >> H[1] >> B[0] >> B[1] >> X >> Y;
    int cou = 0;
    for(int cur = 0; cur <= 1; cur++){
        int Ht[2] = {H[0], H[1]}, Bt[2] = {B[0], B[1]};
        int W_full = X, W_half = Y;
        int res = 0;

        res = cal1(Ht, Bt, W_full, W_half, cur);
        res += cal2(Ht, Bt, W_full, W_half, cur);
        ans = max(ans, res);
        //cout << ++cou << " = " << res << "\n";

        Ht[0] = H[0], Ht[1] = H[1];
        Bt[0] = B[0], Bt[1] = B[1];
        W_full = X, W_half = Y;
        res = 0;

        res = cal2(Ht, Bt, W_full, W_half, cur);
        //cout << "--------------\n";
        /*cout << "CAL2 : " << res << "\n";
        cout << Ht[0] << " " << Ht[1] << " " << Bt[0] << " " << Bt[1] << "\n";
        cout << W_full << " " << W_half << "\n";*/
        res += cal1(Ht, Bt, W_full, W_half, cur);
        //cout << "--------------\n";
        ans = max(ans, res);
        //cout << ++cou << " = " << res << "\n";
    }
    cout << ans << "\n";
    return 0;
}
