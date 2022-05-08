//From most significant bit to least one, move to the bit that differ from the currernt bit if it exists so that the result is as maximum as possible
//https://binarysearch.com/problems/Max-XOR-of-Two-Integers
class trie{
    vector<vector<int>> nxt;
    public:

        trie(){
            nxt.resize(1, vector<int>(2));            
        }

        int ask(int num){
            int node = 0, res = 0;
            // cout << "\nNOW = " << num << "\n";
            for(int i = 30; i >= 0; i--){
                int cur = ((num&(1<<i)) != 0);
                // cout << i << " " << cur << " " << nxt[node][!cur] << " "  << nxt[node][cur] << " ";
                if(nxt[node][!cur] != 0){
                    node = nxt[node][!cur];
                    res |= (!cur)<<i;
                    // cout << "1\n";
                } else if (nxt[node][cur] != 0){
                    node = nxt[node][cur];
                    res |= cur<<i;
                    // cout << "2\n";
                } else {
                    // cout << "3\n";
                    return 0;
                }        
            }
            // cout << "RES : " << res << "\n";
            return res^num;
        }

        void insert(int num){
            int node = 0;
            for(int i = 30; i >= 0; i--){
                int cur = ((num&(1<<i)) != 0);
                if(nxt[node][cur] == 0){
                    nxt[node][cur] = nxt.size();
                    nxt.push_back(vector<int>(2));
                }
                node = nxt[node][cur];
            }
            return;
        }
};


int solve(vector<int>& nums) {
    trie tr;
    int ans = 0;
    for(int num : nums){        
        ans = max(ans, tr.ask(num));
        tr.insert(num);
    }
    
    return ans;   
}