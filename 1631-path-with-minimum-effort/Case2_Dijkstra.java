//Time: 48 ms (91.97%), Space: 43 MB (83.57%) - LeetHub

class Solution {
    
    private static final int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    
    public int minimumEffortPath(int[][] heights) {
        
        int M = heights.length, N = heights[0].length;
        int dist[][] = new int[M][N];
        
        for (int i = 0; i < M; i++)
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        dist[0][0] = 0;
        
        PriorityQueue<int[]> PQ = new PriorityQueue<> ((a, b) -> a[2] - b[2]);    //3번쨰 값만 비교
        PQ.add(new int[] {0, 0, 0});
        
        while (!PQ.isEmpty()) {
            int[] top = PQ.poll();
            int x = top[0], y = top[1];
            
            if (x == M - 1 && y == N - 1) break;    //최소값으로 도달
            
            for (int i = 0; i < 4; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                
                if (next_x < 0 || next_y < 0 || next_x == M || next_y == N) // 유효한 좌표 검사
                    continue;
                
                int _max = Math.max(top[2], Math.abs(heights[x][y] - heights[next_x][next_y])); //현재 경로가 지나온 최대값 비교 갱신
                
                if (_max < dist[next_x][next_y]) {
                    PQ.add(new int[] {next_x, next_y, _max});
                    dist[next_x][next_y] = _max;
                }
            }
        }
        
        return dist[M - 1][N - 1];
    }
}
