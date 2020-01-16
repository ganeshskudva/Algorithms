class Solution {
public List<String> generateSentences(List<List<String>> synonyms, String text) {
        Map<String, List<String>> graph = new HashMap<>();
        for (List<String> synonymPair : synonyms) {
            String w1 = synonymPair.get(0), w2 = synonymPair.get(1);
            connect(graph, w1, w2);
            connect(graph, w2, w1);
        }
        // BFS
        Set<String> ans = new TreeSet<>();
        Queue<String> q = new LinkedList<>();
        q.add(text);
        while (!q.isEmpty()) {
            String out = q.remove();
            ans.add(out); // Add to result
            String[] words = out.split("\\s");
            for (int i = 0; i < words.length; i++) {
                String word = words[i];
                if (graph.get(word) == null) continue;
                for (String neighbor : graph.get(word)) {
                    words[i] = neighbor;
                    String newText = Arrays.stream(words).collect(Collectors.joining(" "));
                    if (!ans.contains(newText)) q.add(newText);
                }
            }
        }
        return new ArrayList<>(ans);
    }

    private void connect(Map<String, List<String>> graph, String v1, String v2) {
        if (graph.get(v1) == null) graph.put(v1, new LinkedList<>());
        graph.get(v1).add(v2);
    }
}
