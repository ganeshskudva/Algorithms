// 261. Graph Valid Tree
class Solution {
    public boolean validTree(int n, int[][] edges) {
        // build the graph using adjacent list
        List<Set<Integer>> graph = new ArrayList<Set<Integer>>();
        for(int i = 0; i < n; i++)
            graph.add(new HashSet<Integer>());
        for(int[] edge : edges)
        {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        
        // no cycle
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new ArrayDeque<Integer>();
        queue.add(0);
        while(!queue.isEmpty())
        {
            int node = queue.poll();
            if(visited[node])
                return false;
            visited[node] = true;
            for(int neighbor : graph.get(node))
            {
                queue.offer(neighbor);
                graph.get(neighbor).remove((Integer)node);
            }
        }
        
        // fully connected
        for(boolean result : visited)
        {
            if(!result)
                return false;
        }
        
        return true;
    }
}
