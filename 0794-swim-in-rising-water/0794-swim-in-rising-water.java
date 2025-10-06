import java.util.*;

class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        boolean[][] visited = new boolean[n][n];

        // Min-heap: stores (time, row, col)
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{grid[0][0], 0, 0});

        // 4-directional movement
        int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int time = current[0];
            int r = current[1];
            int c = current[2];

            // If we reached bottom-right cell, return time
            if (r == n - 1 && c == n - 1) return time;

            // Skip if already visited
            if (visited[r][c]) continue;
            visited[r][c] = true;

            // Check all 4 directions
            for (int[] dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int newTime = Math.max(time, grid[nr][nc]);
                    pq.offer(new int[]{newTime, nr, nc});
                }
            }
        }
        return -1; // should never reach here
    }
}
