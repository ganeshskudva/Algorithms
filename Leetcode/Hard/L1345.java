class Solution {
    public int minJumps(int[] arr) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for(int i=0;i<arr.length;i++){
            if(map.containsKey(arr[i])==false){
                map.put(arr[i], new HashSet<>());
            }
            map.get(arr[i]).add(i);
        }
        
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        boolean[] visited = new boolean[arr.length];
        visited[0] = true;
        
        int step = 0;
        while(queue.size()!=0){
            int size = queue.size();
            for(int i=0;i<size;i++){
                int cur = queue.poll();
                if(cur == arr.length-1){
                    return step;
                }
                if(cur-1>=0 && visited[cur-1]==false){
                    queue.offer(cur-1);
                    visited[cur-1] = true;;
                }
                if(cur+1<arr.length && visited[cur+1]==false){
                    queue.offer(cur+1);
                    visited[cur+1] = true;
                }
                if(map.containsKey(arr[cur])==false){
                    continue;
                }
                for(Integer next_index: map.get(arr[cur])){
                    if(next_index!=cur && visited[next_index]==false){
                        queue.offer(next_index);
                        visited[next_index] = true;
                    }
                }
                map.get(arr[cur]).clear();
            }
            step++;
        }
        
        return -1;
    }
}
