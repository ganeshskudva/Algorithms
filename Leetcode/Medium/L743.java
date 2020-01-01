class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
    if (times == null || times.length == 0) {
        return -1;
    }

    /* Subproblem: dp(i) represents minimum distance from K to i (iteratively update dp(i) when we find another shorter distance from K to i)*/
    int[] dp = new int[N + 1];

    /* Base case 1: initialize MAX value as initial minimum distance from K to every point*/
    /* Base case 2: initialize 0 as min distance to K itself*/
    for (int i = 0; i < N + 1; i++) {
        dp[i] = Integer.MAX_VALUE;
    }
    dp[K] = 0;

    /* traverse all destinations*/
    for (int i = 0; i < N; i++) {
        for (int[] edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];

            /* if dp[u] (starting point of current edge) has already been visited, and new distance from u to v is smaller than previous saved distance
            we should update minimum distance from u to v*/
            if (dp[u] != Integer.MAX_VALUE && dp[v] > dp[u] + w) {
                dp[v] = dp[u] + w;
            }
        }
    }

    /* after getting minimum distance (travel time) to all points, we should retrieve the max distance from these minimum distance, 
     * to ensure that we can travel all points in a specific travel time
    */
    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = Math.max(result, dp[i]);
    }
    /* if we do not visit all points, we should return -1*/
    return result == Integer.MAX_VALUE ? -1 : result;
}      
}
