#include<vector>
#include<iostream>
#include<utility>
using namespace std;
vector<pair<int,int>> vec;
int n,i,maxx,temp,j,cou,code,maxy;
main()
{
    cin >> n;
    for(i=0;i<n;i++)
    {
        code = 0;
        cin >> temp;
        for(int j=0;j<cou;j++)
        {
            if(vec[j].first==temp)
            {
                vec[j].second +=1;
                code = 1;
                if(vec[j].second>maxx)
                {
                    maxx = vec[j].second;
                }
                break;
            }
        }
            if(code==0){
            vec.push_back(make_pair(temp,1));
            if(vec[cou].second>maxx)
            {
                maxx = vec[cou].second;
            }
            cou+=1;
            }
    }
    for(i=0;i<cou;i++)
    {
        if(vec[i].second == maxx){
                if(vec[i].first > maxy){
                    maxy = vec[i].first;
                    temp = i;
                }
        }
    }
        cout << vec[temp].first << endl << vec[temp].second;
}
