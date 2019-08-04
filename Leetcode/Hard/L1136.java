// 1136. Parallel Courses
class Solution {
    public int minimumSemesters(int N, int[][] relations) {
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        int[] inDegree = new int[N + 1];
        
        for(int i = 1; i <= N; i++) {
            graph.put(i, new HashSet<>());
        }
        for(int[] edge : relations) {
            if(graph.get(edge[0]).add(edge[1])) {
                inDegree[edge[1]]++;
            }
        }   
        
        Queue<Integer> q = new LinkedList<>();
        int semester = 0, course = 0;
        for(int i = 1; i <= N; i++) {
            if(inDegree[i] == 0) {
                q.add(i);           
            }
        }
        while(q.size() > 0) {
            int sz = q.size();
            course += sz;
            for(int i = 0; i < sz; i++) {
                int curr = q.poll();
                for(int neighbor : graph.get(curr)) {
                    inDegree[neighbor]--;
                    if(inDegree[neighbor] == 0) {
                        q.add(neighbor);
                    }
                }               
            }
            semester++;
        }
        return course == N ? semester : -1;
    }
}
