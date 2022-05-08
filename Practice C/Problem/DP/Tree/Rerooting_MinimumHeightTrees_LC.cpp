class Solution {
///https://leetcode.com/problems/minimum-height-trees/
public:
    vector<vector<int>> G;
    int hs[20010],hp[20010],mx[20010][2],from[20010], res = 1e9, mn[20010];

    void dfs1(int u, int p){
        hs[u] = 1;
        for(int v : G[u]){
            if(v == p) continue;

            dfs1(v, u);

            hs[u] = max(hs[u], hs[v]+1);


            int tmp = hs[v]+1, node = v;
            if(tmp > mx[u][0]){
                swap(tmp, mx[u][0]);
                swap(node, from[u]);
            }
            //cout << u << " " << v << " " << tmp << " " << mx[u][1] << "\n";
            if(tmp > mx[u][1]){
                swap(tmp, mx[u][1]);
            }
        }
    }

    void dfs2(int u, int p){
        mn[u] = max(hs[u], hp[u]+1);
        res = min(res, mn[u]);
        for(int v : G[u]){
            if(v == p) continue;

            if(v != from[u])
                hp[v] = max(hp[u]+1, mx[u][0]);
            else
                hp[v] = max(hp[u]+1, mx[u][1]);

            dfs2(v, u);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        G.resize(n+5);
        for(int i = 0; i < n-1; i++){
            edges[i][0]++; edges[i][1]++;
            //cout << edges[i][0] << " " << edges[i][1] << "\n";
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]);
        }

        dfs1(1, 0);

        dfs2(1, 0);

        vector<int> ans;
        cout << "RES : " << res << "\n";
        for(int i = 1; i <= n; i++){
            cout << hs[i] << " " << hp[i] << " " << from[i] << "\n";
        }
        cout << "\n";
        for(int i = 1; i <= n; i++){
            cout << mx[i][0] << " " << mx[i][1] << "\n";
        }
        cout << "\n";

        for(int i = 1; i <= n; i++){
            if(mn[i] == res){
                ans.push_back(i-1);
            }
        }

        return ans;
    }
};
