#include<bits/stdc++.h>
using namespace std;
int n,m,cou,ans;
char c[50][50];
bool visit[50][50];
queue< pair<int,int> > qq;
main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> c[i][j];
        }
    }
     for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            visit[i][j] = false;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(visit[i][j]==false)
                qq.push({i,j});
                cou=0;
                //cout << cou;
                //cout << i << " " << j << endl;
            while(!qq.empty())
            {
                int pr[] = {-1,0,0,1},pl[] = {0,-1,1,0};
                int row = qq.front().first;
                int col = qq.front().second;
                qq.pop();
                if(visit[row][col]==true)
                    continue;
                visit[row][col] = true;
                if(c[row][col+1]!='#'&&c[row][col-1]!='#'&&c[row][col]=='.'&&c[row+1][col]!='#'&&c[row-1][col]!='#')
                {
                    visit[row][col] = true;
                    cou++;
                    //cout << row << " " << col << endl;
                }else{
                    continue;
                }

                for(int k=0; k<4; k++)
                {
                    if(row+pr[k]<1||col+pl[k]<1||row+pr[k]>n||col+pl[k]>m)
                        continue;
                    if(c[row+pr[k]][col+pl[k]]=='#'){
                        visit[row+pr[k]][col+pl[k]] = true;
                        continue;
                    }
                    if(visit[row+pr[k]][col+pl[k]]==true)
                        continue;

                    qq.push({row+pr[k],col+pl[k]});
                    //cout << row+pr[k] << " " << col+pl[k] << endl;
                }
                ans = max(ans,cou);
            }
        }
    }

    cout << ans;
}
