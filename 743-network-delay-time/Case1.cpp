//Time: 134 ms (76.76%), Space: 41.9 MB (48.12%) - LeetHub


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& i : times) 
            graph[i[0]].push_back({i[1], i[2]});
        
        vector<bool> visited(n, false);
        
        priority_queue<pair<int, int>> q;
        q.push({0, k});
        
        int _max = INT_MIN;
        int cnt = 0;
        while (!q.empty()) {
            
            int time = -q.top().first;
            int cur = q.top().second;
            q.pop();
            
            if (visited[cur])
                continue;
            
            _max = max(_max, time);
            visited[cur] = true;
            ++cnt;
            for (auto& i : graph[cur])
                q.push({-(i.second + time), i.first});
        }
        return cnt == n ? _max : -1;
    }
};
