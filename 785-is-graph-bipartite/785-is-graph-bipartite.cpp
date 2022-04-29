class Solution {
    
private:
    vector<int> visited;
public:
    
    bool DFS(vector<vector<int>>& graph, int x) {
        
        for (auto& next : graph[x]) {
            if (!visited[next]) {
                visited[next] = 3 - visited[x];
                if (!DFS(graph, next))
                    return false;
            }else if (visited[next] == visited[x])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        visited.assign(graph.size(), 0);
        
        for (int i = 0; i < graph.size(); i++)
            if (!visited[i]) {
                visited[i] = 1;
                if (!DFS(graph, i))
                    return false;;
            }
        return true;
    }
};