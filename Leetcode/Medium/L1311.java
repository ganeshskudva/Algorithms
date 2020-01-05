class Solution {
    public static List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        boolean[] visited = new boolean[friends.length];
        List<List<Integer>> frnds = new ArrayList<List<Integer>>();
        for (int i = 0; i < friends.length; i++) {
            frnds.add(i, new ArrayList<Integer>());
            int[] e = friends[i];
            for (int j = 0; j < e.length; j++) {
                frnds.get(i).add(e[j]);
            }
        }

        int lvl = 0;
        Map<Integer, List<Integer>> mp = new HashMap<Integer, List<Integer>>();
        Queue<Integer> q = new LinkedList<Integer>();
        q.offer(id);

        while (!q.isEmpty()) {
            int size = q.size();
            mp.put(lvl, new ArrayList<Integer>());
            for (int i = 0; i < size; i++) {
                Integer n = q.poll();
                if (visited[n])
                    continue;;
                visited[n] = true;
                mp.get(lvl).add(n);
                for (int nei: frnds.get(n)) {
                    if (!visited[nei])
                        q.offer(nei);
                }
            }
            lvl++;
        }

        List<Integer> f = mp.get(level);
        Map<String, Integer> tm = new TreeMap<String, Integer>();
        for (int fr: f) {
            List<String> wt = watchedVideos.get(fr);
            for (String s: wt)
                tm.put(s, tm.getOrDefault(s, 0)+1);
        }
        
        Map<String, Integer> retMap = sortByValue(tm);
        List<String> ret = new ArrayList<String>();
        for (Map.Entry<String, Integer> e: retMap.entrySet())
            ret.add(e.getKey());

        return ret;

    }

    public static <K, V extends Comparable<? super V>> Map<K, V> sortByValue(Map<K, V> map) {
        List<Map.Entry<K, V>> list = new ArrayList<>(map.entrySet());
        list.sort(Map.Entry.comparingByValue());

        Map<K, V> result = new LinkedHashMap<>();
        for (Map.Entry<K, V> entry : list) {
            result.put(entry.getKey(), entry.getValue());
        }

        return result;
    }
}
