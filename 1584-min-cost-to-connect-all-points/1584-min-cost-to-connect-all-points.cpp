struct node {
    int from, to, dist;
    
    bool operator()(const node& a, const node& b) {
        return a.dist > b.dist;
    }
};

class Solution {
    vector<int> parent;
public:
    
    inline int GetManhattanDistance(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    
    int Findp(int a) {
        if (parent[a] < 0) return a;
        return parent[a] = Findp(parent[a]);
    }
    
    bool Union(int a, int b) {
        int x = Findp(a);
        int y = Findp(b);
        
        if (x == y) return false;
        
        if (parent[x] < parent[y]) {
            parent[x] += parent[y];
            parent[y] = x;
        }
        else {
            parent[y] += parent[x];
            parent[x] = y;
        }
        return true;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0;
        int N = points.size();
        
        priority_queue<node, vector<node>, node> pq;
        parent.assign(N, -1);
            
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) 
                pq.push({i, j, GetManhattanDistance(points[i], points[j])});
            
        
        for (int i = 0; i < N - 1; pq.pop()) {
            int from = pq.top().from;
            int to = pq.top().to;
            int dist = pq.top().dist;
            
            if (Union(from, to)) {
                ans += dist;
                i++;
            }
        }
        
        return ans;
    }
};