#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using pi = pair<int,int>;
using ll = long long;

int lim = 1e6,posp[N],num_prime[N];
vector<int> prime,made_from[N];
vector<tuple<int,int,int>> query;
ll ans[55];

///https://beta.programming.in.th/tasks/tumso17_factorial

int bi(int val){
    int l = 0, r = prime.size()-1, res = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(num_prime[mid] >= val){
            res = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return res+1;
}

int main(void){

    for(int i = 2; i <= lim; i++){
        if(made_from[i].size()) continue;
        posp[i] = prime.size();
        prime.emplace_back(i);
        for(int j = i; j <= lim; j+=i){
            made_from[j].emplace_back(i);
        }
    }
    //cout << prime.size() << "\n";

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n,K; cin >> n >> K;
        query.emplace_back(n, K, i);
    }
    sort(query.begin(), query.end());

    int old = 1;
    for(auto [n, K, idx] : query){
        while(old <= n){
            for(int p : made_from[old]){
                int tmp = old;
                while(tmp % p == 0){
                    tmp /= p;
                    num_prime[posp[p]]++;
                }
            }
            old++;
        }

        if(K == 1){ ///num_div = 1
            ans[idx] = 1; continue;
        }

        ///Factorization K
        vector<int> div;
        int tmp = K, num_div = 1;
        for(int p : prime){
            if(p > tmp) break;
            int cou = 0;
            while(tmp % p == 0){
                tmp /= p;
                cou++;
            }
            if(cou > 0){
                div.emplace_back(p);
                num_div *= (cou+1);
            }
        }
        if(tmp != 1){
            div.emplace_back(tmp);
            num_div *= 2;
        }

        bool iscube = false;
        if(div.size() == 1 and num_div == 4){
            iscube = true;
            div.emplace_back(div.back()*div.back());
        }

        ans[idx] += bi(K-1);

        if(num_div == 3 or iscube){ ///square or cube
            ll A = bi(div[0]-1);
            if(num_div == 3)
                ans[idx] += A*(A-1)/2;
            else
                ans[idx] += A*(A-1)*(A-2)/6;
        }

        if(num_div == 4){ ///2 factors
            ll B = bi(div[0]-1);
            ll C = bi(div[1]-1);
            ans[idx] += C*(B-1);
        }
    }

    for(int i = 1; i <= t; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
