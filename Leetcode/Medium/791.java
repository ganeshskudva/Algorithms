class Solution {
    public String customSortString(String S, String T) {
        Map<Character, Integer> mp = new HashMap<>();

        for (int i = 0; i < T.length(); i++)
            mp.put(T.charAt(i), mp.getOrDefault(T.charAt(i), 0) + 1);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < S.length(); i++) {
            if (mp.containsKey(S.charAt(i))) {
                for (int j = 0; j < mp.get(S.charAt(i)); j++) {
                    char ch = S.charAt(i);
                    //sb.append(mp.get(S.charAt(i) + 'a'));
                    sb.append(ch);
                }
            }
            mp.put(S.charAt(i), 0);
        }

        for (Character key: mp.keySet()) {
            if (mp.get(key) > 0) {
                for (int i = 0; i < mp.get(key); i++)
                    sb.append(key);
            }
        }

        return sb.toString();
    }
}
