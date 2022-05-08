#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10, NP = 1e5+10;
using pi = pair<int,int>;
using ll = long long;

int lim = 1e6,posp[N];
bool chk[N];
vector<int> prime,made_from[N];
vector<tuple<int,int,int>> query;
ll ans[55];

int bi(int val, vector<int> &num_prime){
    int l = 0, r = (int)num_prime.size()-1, res = -1;
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
        if(chk[i]) continue;
        prime.emplace_back(i);
        for(int j = i; j <= lim; j+=i){
            chk[j] = true;
        }
    }
    //cout << prime.size() << "\n";
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n,K; cin >> n >> K;
        query.emplace_back(n, K, i);
    }
    //sort(query.begin(), query.end());
    int old = 1;
    for(auto [n, K, idx] : query){

        vector<int> val;
        for(int p : prime){
            if(p > n) break;
            int tmp = n, cou = 0;
            while(tmp){
                cou += tmp/p;
                tmp /= p;
            }
            val.emplace_back(cou);
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
            div.emplace_back(div.back()*div.back()); ///for case -> if(num_div == 4)
        }

        ans[idx] += bi(K-1, val);
        if(num_div == 3 or iscube){ ///square or cube
            ll A = bi(div[0]-1, val);
            if(num_div == 3)
                ans[idx] += A*(A-1)/2;
            else
                ans[idx] += A*(A-1)*(A-2)/6;
        }

        if(num_div == 4){ ///2 factors -> 2 cases: cube or product of 2 prime
            ll B = bi(div[0]-1, val);
            ll C = bi(div[1]-1, val);
            ans[idx] += C*(B-1);
        }

    }
    for(int i = 1; i <= t; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
