#include<bits/stdc++.h>
using namespace std;
bool visit[100005];
int V,E;
vector<int> vec[100005];
stack<int> st;
void TOPO(int x)
{
    visit[x] = true;
    for(int i=0; i<vec[x].size(); i++)
    {
        int dest = vec[x][i];
        if(!visit[dest])
            TOPO(dest);
    }
    st.push(x);
    return;
}
main()
{
    while(1)
    {
        scanf("%d %d",&V,&E);
        if(V==0)
            return 0;
        for(int i=0; i<E; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            vec[x].push_back(y);
        }
        for(int i=1; i<=V; i++)
        {
            if(!visit[i])
                TOPO(i);
        }
        //printf("Topological sort: ");
        while(!st.empty())
        {
            printf("%d ",st.top());
            st.pop();
        }
        for(int i=0; i<=V; i++)
        {
            vec[i].clear();
            visit[i] = false;
        }
        printf("\n");
    }
    return 0;
}
/*
5 4
1 2
2 3
1 3
1 5
*/
