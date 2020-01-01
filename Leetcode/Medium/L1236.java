/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface HtmlParser {
 *     public List<String> getUrls(String url) {}
 * }
 */
class Solution {
    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        List<String> lst = new ArrayList<>();
        if (startUrl == null)
            return lst;

        int i, j;
        Map<String, Boolean> map = new HashMap<>();
        String base = getHostname(startUrl);
        Queue<String> q = new LinkedList<>();
        q.offer(startUrl);

        while (!q.isEmpty()) {
            int size = q.size();
            for (i = 0; i < size; i++) {
                String n = q.poll();
                if (map.containsKey(n))
                    continue;
                map.put(n, true);
                lst.add(n);
                for (String s: htmlParser.getUrls(n)) {
                    if (s.contains(base)) {
                        if (!map.containsKey(s)) {
                            q.offer(s);
                        }
                    }
                        
                }
            }
        }
        
        return lst;
    }
    
    private String getHostname(String Url) {
        String[] ss = Url.split("/");
        return ss[2];
    }
}
