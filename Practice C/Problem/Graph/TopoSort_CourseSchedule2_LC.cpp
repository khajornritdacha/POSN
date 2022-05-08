class Solution {
///https://leetcode.com/problems/course-schedule-ii/submissions/
public:
    vector<int> G[2010],res;
    int vi[2010];
    bool cycle = false;

    bool topo(int u){
        if(vi[u]){ return vi[u] == 1; }
        vi[u] = 1;
        for(int v : G[u]){
            if(topo(v)) return true;
        }
        vi[u] = 2;
        res.push_back(u);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            G[u].push_back(v);
        }

        for(int i = 0; i < n; i++){
            if(!vi[i])
                cycle |= topo(i);
        }

        vector<int> ans;
        if(cycle) return ans;
        return res;
    }
};
