#include<bits/stdc++.h>
using namespace std;
char c[1010][1010];
int row,col,pa=0,ps=0,pm=0;
vector< pair<int,int> > vec;
queue< pair<int,int> > qq;
bool visit[1010][1010];
main()
{
    cin >> col >> row;
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            cin >> c[i][j];
            if(c[i][j]=='1')
            {
                vec.push_back({i,j});
            }
        }
    }
    for(int k=0; k<vec.size(); k++)
    {
        int nr = vec[k].first;
        int nc = vec[k].second;
        if(visit[nr][nc]==true)
            continue;
        //cout << nr << " " << nc << "\n";
        int minx = nr,maxx = nr,miny = nc,maxy = nc,cnt = 0;
        qq.push({nr,nc});
        while(!qq.empty())
        {
            int nowrow = qq.front().first;
            int nowcol = qq.front().second;
            qq.pop();
            visit[nowrow][nowcol] = true;
            int pr[]= {-1,0,0,1},pc[]= {0,-1,1,0};
            for(int i=0; i<4; i++)
            {
                int gr = nowrow+pr[i];
                int gc = nowcol+pc[i];
                if(gr<1||gc<1||gr>row||gc>col)
                    continue;
                if(c[gr][gc]=='0')
                    continue;
                if(visit[gr][gc]==true)
                    continue;
                minx = min(minx,gr);
                maxx = max(maxx,gr);
                miny = min(miny,gc);
                maxy = max(maxy,gc);
                visit[gr][gc] = true;
                qq.push({gr,gc});
            }
        }
        if(c[minx][miny]=='1')//ถ้า check 4 มุมจะได้แค่ 90  มร.ทำไม
        {
            cnt++;
        }
        if(c[maxx][maxy]=='1')
            cnt++;
        if(cnt==2)
            pa++;
        else if(cnt==0)
            ps++;
        else if(cnt==1)
            pm++;
        //cout << cnt << "\n";
    }
    cout << pa << " " << ps << " " << pm;
}
