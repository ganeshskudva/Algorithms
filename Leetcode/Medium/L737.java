class Solution {
public boolean isConnected(HashMap<String, List<String>> graph, String start, String end, HashSet<String> visited) {
        if(start.equals(end)){
            return true;
        }
        if(visited.contains(start)){
            return false;
        }
        visited.add(start);
        List<String> neighbors = graph.get(start);
        if(neighbors == null) {
            return false;
        }
        boolean ans = false;
        for(String x: neighbors) {
            ans = ans || isConnected(graph, x, end, visited);
        }
        return ans;
    }
    
    public boolean areSentencesSimilarTwo(String[] words1, String[] words2, List<List<String>> pairs) {
        if(words1.length != words2.length){
            return false;
        }
        HashMap<String, List<String>> graph = new HashMap();
        for(List<String> list : pairs) {
            List<String> temp = graph.getOrDefault(list.get(0), new LinkedList());
            temp.add(list.get(1));
            graph.put(list.get(0), temp);
            
            temp = graph.getOrDefault(list.get(1), new LinkedList());
            temp.add(list.get(0));
            graph.put(list.get(1), temp);        
        }
        for(int i=0;i<words1.length;i++){
            if(!isConnected(graph, words1[i], words2[i], new HashSet())){
                return false;
            }
        }
        return true;
    }
}
