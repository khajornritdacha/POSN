#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string str;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> str;
    for(int i=0; i<n; i++)
    {
        if(str[i]=='S'&&str[i+1]=='P'&&str[i+2]=='A'&&str[i+3]=='C'&&str[i+4]=='E'&&str[i+5]=='B'&&str[i+6]=='A'&&str[i+7]=='R')
        {
            ans++;
            i+=7;
            //cout << i;
        }
        else if(str[i]=='S'&&str[i+1]=='H'&&str[i+2]=='I'&&str[i+3]=='F'&&str[i+4]=='T')
        {
            ans++;
            i+=4;
        }
        else if(str[i]=='Q')
        {
            ans++;
        }
        else if(str[i]=='W')
        {
            ans++;
        }
        else if(str[i]=='E')
        {
            ans++;
        }
        else if(str[i]=='A')
        {
            ans++;
        }
        else if(str[i]=='S')
        {
            ans++;
        }
        else if(str[i]=='D')
        {
            ans++;
        }
        else if(str[i]=='V')
        {
            ans++;
        }
    }
    cout << ans;
}
