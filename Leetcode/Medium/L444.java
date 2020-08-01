class Solution {
    public boolean sequenceReconstruction(int[] org, List<List<Integer>> seqs) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        Map<Integer, Integer> indegree = new HashMap<>();
        for (List<Integer> seq : seqs) {
            for (int i = 0; i < seq.size(); i++) {
                graph.putIfAbsent(seq.get(i), new ArrayList<Integer>());
                indegree.putIfAbsent(seq.get(i), 0);
                if (i > 0) {
                    graph.get(seq.get(i - 1)).add(seq.get(i));
                    indegree.put(seq.get(i), indegree.getOrDefault(seq.get(i), 0) + 1);
                }
            }
        }
        if (org.length != indegree.size()) {
            return false;
        }

        Queue<Integer> q = new LinkedList<>();
        for (Map.Entry<Integer, Integer> entry : indegree.entrySet()) {
            if (entry.getValue() == 0) {
                q.add(entry.getKey());
            }
        }

        int index = 0;
        while (!q.isEmpty()) {
            if (q.size() > 1) {
                return false;
            }
            int curr = q.poll();
            if (org[index++] != curr) {
                return false;
            }
            for (int nb : graph.get(curr)) {
                indegree.put(nb, indegree.get(nb) - 1);
                if (indegree.get(nb) == 0) {
                    q.add(nb);
                }
            }
        }
        return index == org.length;
    }
}
