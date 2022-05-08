#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
string s,l;
int q,dp[1005][1005];
main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> l >> q;
	while(q--){
        string str;
        cin >> str;
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=l.size();j++){
                if(i==0&&j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=dp[i][j-1]&&(l[j-1]==str[i+j-1]);
                else if(j==0)
                    dp[i][j]=dp[i-1][j]&&(s[i-1]==str[i+j-1]);
                else
                    dp[i][j]=dp[i][j-1]&&(l[j-1]==str[i+j-1]) || dp[i-1][j]&&(s[i-1]==str[i+j-1]);
            }
        }
        if(dp[s.size()][l.size()])
            cout << "Yes\n";
        else
            cout << "No\n";
        /*for(int i=0;i<=s.size();i++){
            for(int j=0;j<=l.size();j++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";*/
	}
}

