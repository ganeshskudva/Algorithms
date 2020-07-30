class Solution {
int maxLen = 0;
    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> hs = new HashSet<>();
        for(String w: wordDict)
        {
            hs.add(w);
            if(w.length()>maxLen) maxLen = w.length(); //get the maxLen of words
        }
        Map<Integer, List<String>> map = new HashMap<>();
        return helper(hs, s, 0, map);      
    }
    
    public List<String> helper(Set<String> hs, String s, int start, Map<Integer, List<String>> map)
    {
        if(map.containsKey(start)) return map.get(start);
        List<String> list = new ArrayList<>(); 
        if(start==s.length())  list.add("");
        //reduce the # of iterations using maxLen
        for(int i=start; i<start+maxLen&&i<s.length(); i++)
        {
            if(hs.contains(s.substring(start, i+1)))
            {
                List<String> nexts = helper(hs, s, i+1, map);
                for(String next:nexts)
                {
                    if(next=="")//reaches the end
                        list.add(s.substring(start, i+1)+next);
                    else
                        list.add(s.substring(start, i+1) + " " + next);
                }
            }
        }
        map.put(start, list); 
        return list;
    }
}
