class Solution {
    public long gridGame(int[][] grid) {
        long[] pre1 = new long[grid[0].length];
        long[] pre2 = new long[grid[0].length];

        for(int i=0; i<grid[0].length; i++){
            pre1[i] = grid[0][i];
            pre2[i] = grid[1][i];
        }
        
        
        
        for(int i=1; i<grid[0].length; i++){
            pre1[i] += pre1[i-1];
            pre2[i] += pre2[i-1];
        }
        

        long res = Long.MAX_VALUE;
        for(var i=0; i< grid[0].length; i++){
            long top = pre1[pre1.length-1]- pre1[i];
            long bottom = i > 0 ? pre2[i - 1] : 0;
            long second = Math.max(top, bottom);
            res = Math.min(res, second);
        }
        return res;
    }
}