class Solution {
public boolean isBipartite(int[][] graph) {
        if (graph.length == 0)
            return false;

        List<List<Integer>> lst = new ArrayList<>();
        for (int i = 0; i < graph.length; i++) {
            lst.add(i, new ArrayList<>());
            int[] ed = graph[i];
            for (int e: ed)
                lst.get(i).add(e);
        }


        boolean[] visited = new boolean[graph.length];
        int[] color = new int[graph.length];
        color[0] = 1;
        Queue<Integer> q = new LinkedList<>();


        for (int i = 0; i < graph.length; i++) {
            if (!visited[i]) {
                q.offer(i);
                color[i] = 1;

                while ((!q.isEmpty())) {
                    int size = q.size();
                    for (int j = 0; j < size; j++) {
                        Integer node = q.poll();
                        if (visited[node])
                            continue;

                        visited[node] = true;

                        for (Integer nei: lst.get(node)) {
                            if (color[nei] == color[node])
                                return false;
                            if (!visited[nei]) {
                                color[nei] = -color[node];
                                q.offer(nei);
                            }
                        }
                    }

                }
            }
        }

        return true;
    }
}
