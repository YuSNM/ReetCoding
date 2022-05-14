class Solution {
    const int INF = 10001;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& i : times) 
            graph[i[0]].push_back({i[1], i[2]});
        
        vector<int> dist(n + 1, INF);
        dist[k] = 0;
        
        queue<int> q;
        q.push(k);
        
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            
            for (auto& i : graph[next])
                if (dist[i.first] > dist[next] + i.second) {
                    dist[i.first] = dist[next] + i.second;
                    q.push(i.first);
                }
        }
        
        int _max = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF)
                return -1;
            _max = max(_max, dist[i]);
        }
        
        return _max;
    }
};