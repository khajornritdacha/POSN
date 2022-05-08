class Solution {
///https://leetcode.com/problems/course-schedule/submissions/
public:
    int n,vi[100010],cnt = 0;
    bool cycle = false;
    vector<int> G[100010];

    bool topo(int u){
        if(vi[u]){
            return vi[u] == 1;
        }
        vi[u] = 1;
        cnt++;
        for(int v : G[u]){
            if(topo(v)) return true;
        }
        vi[u] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            G[u].push_back(v);
        }

        for(int i = 0; i < n; i++){
            if(!vi[i])
                cycle |= topo(i);
        }

        cout << cycle << "\n";
        if(cycle or cnt != n) return false;
        return true;
    }
};
