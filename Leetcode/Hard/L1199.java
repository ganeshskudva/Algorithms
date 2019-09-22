	// 1199. Minimum Time to Build Blocks
  // https://www.youtube.com/watch?v=pSW8wxvcEcM
  class Solution {
	    public int minBuildTime(int[] a, int split) {
	        PriorityQueue<Integer> pq = new PriorityQueue<>();
	        for(int v : a)pq.add(v);
	        while(pq.size() >= 2){
	        	int x = pq.poll();
	        	int y = pq.poll();
	        	pq.add(y + split);
	        }
	        return pq.poll();
	    }
	}


class Solution {
    public int minBuildTime(int[] blocks, int split) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int b : blocks) pq.add(b);
        while(pq.size() > 1) {
            pq.poll();
            pq.add(pq.poll() + split);
        }
        return pq.poll();
    }
}
