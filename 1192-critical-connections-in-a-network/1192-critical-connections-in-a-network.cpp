class Solution {
    int time = 0;
    vector<int> low;
    vector<vector<int>> adj;
    vector<vector<int>> ans;
public:
    int bcc_dfs(int u, int prev = -1) {
        
        int val = low[u] = ++time;
        for (int v : adj[u]) {
            
            if (v == prev)
                continue;
            
            if (low[v]) 
                val = min(val, low[v]);
            else {
                int next_val = min(bcc_dfs(v, u), low[v]);
                
                if (next_val > low[u])
                    ans.push_back({u, v});
                val = min(next_val, val);
            }
        }
        return val;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        low.resize(n);
        adj.resize(n);
        
        for (auto& p : connections) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
            
        for (int i = 0; i < n; i++)
            if (!low[i])
                bcc_dfs(i);
                
        return ans;
        
    }
};