//Time: 1 ms (83.33%), Space: 53.7 MB (47.00%) - LeetHub

class Solution {
    int[] visited;
    
    private boolean DFS(int[][] graph, int x) {
        
        for (int next : graph[x]) {
            if (visited[next] == 0) {
                visited[next] = 3 - visited[x];
                if (!DFS(graph, next))
                    return false;
            }else if (visited[next] == visited[x])
                return false;
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
    
        visited = new int[graph.length];
        
        for (int i = 0; i < graph.length; i++) 
            if (visited[i] == 0) {
                visited[i] = 1;
                if (!DFS(graph, i))
                    return false;
            }
        
        return true;
    }
}
