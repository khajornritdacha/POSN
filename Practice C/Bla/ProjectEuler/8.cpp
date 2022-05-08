#include <bits/stdc++.h>
using namespace std;


int main(void){
    string str,pre;
    long long now = 1, mx = 0, zero = 0;
    bool fir = false;
    int K = 13;
    while(cin >> str){
        //cout << "TEST : " << str << "\n";
        if(!fir){
            for(int i = 0; i < str.size(); i++){
                //cout << "I : " << i << " " << str[i] << "\n";
                if(i >= K){
                    if(str[i-K]-'0' == 0){
                        zero--;
                    }else{
                        now /= (str[i-K]-'0');
                    }
                }
                if(str[i] != '0')
                    now *= (str[i]-'0');
                else
                    zero++;
                if(zero == 0)
                    mx = max(mx, now);
            }
            fir = true;
        }else{
            int ip = pre.size()-K;
            for(int i = 0; i < str.size(); i++){
                if(ip < pre.size()){
                    if(pre[ip]-'0' == 0){
                        zero--;
                    }else{
                        now /= (pre[ip]-'0');
                    }
                    ip++;
                }else{
                    if(str[i-K]-'0' == 0){
                        zero--;
                    }else{
                        now /= (str[i-K]-'0');
                    }
                }
                if(str[i] != '0')
                    now *= (str[i]-'0');
                else
                    zero++;
                if(zero == 0)
                    mx = max(mx, now);
            }
        }
        //cout << "TEST2 : " << str << "\n";
        pre = str;
    }
    cout << mx << "\n";
    return 0;
}
