#include<bits/stdc++.h>
using namespace std;

int n,fi,se,th;
char cc;
bool un[15];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        for(int i=0; i<=9; i++)
            un[i] = false;
        cin >> n;
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            un[x] = true;
        }
        cin >> fi >> cc >> se >> cc >> th;
        int rfi, rse, rth, cnt, all, dfi, dse, dth, sum=0, sum2=0;
        all = fi*6000+se*100+th;
        rfi = rse = rth = cnt = dfi = dse = dth = 0;
        while(rth*10+dth != th){
            if(un[rth] or un[dth]){
                cnt++;
                sum2++;
            }
            dth++;
            if(dth == 10)
                rth++, dth=0;
        }
        if(fi != 0){
            while(true){
                if(un[rse] or un[dse]){
                    sum += 100;
                }else{
                    sum += (10*n)+(10-n)*n;
                }
                dse++;
                if(dse == 10)
                    rse++, dse=0;
                if(rse == 6){
                    rse=0;
                    break;
                }
            }
        }
        //cout << "SUM : " << sum << "\n";

        while(rse*10+dse != se){
            if(un[rse] or un[dse]){
                cnt += 100;
                sum2 += 100;
            }else{
                cnt += (10*n)+(10-n)*n;
                sum2 += (10*n)+(10-n)*n;
            }
            dse++;
            if(dse == 10)
                dse = 0, rse++;
        }
        //cout << "SUM2 : " << sum2 << "\n";

        //cout << "BF : " << cnt << "\n";
        while(rfi*10+dfi != fi){
            if(un[rfi] or un[dfi]){
                cnt += 6000;
                //cout << "6000\n";
            }else{
                cnt += sum;
            }
            dfi++;
            if(dfi == 10)
                rfi++, dfi=0;
        }

        all -= cnt;
        //cout << "CNT : " << all << " " << cnt << " " << sum << "\n";
        if(all/6000 <= 9)
            cout << 0;
        cout << all/6000 << ":";
        all%=6000;
        if(all/100 <= 9)
            cout << 0;
        cout << all/100 << ":";
        all%=100;
        if(all <= 9)
            cout << 0;
        cout << all << "\n";
    }
}
