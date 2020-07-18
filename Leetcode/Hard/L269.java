public String alienOrder(String[] words) {
        if (words == null || words.length == 0)
            return "";
        Map<Character, Set<Character>>  mp = new HashMap<>();
        Map<Character, Integer> indegree = new HashMap<>();

        for (String s: words) {
            for (int i = 0; i < s.length(); i++)
                indegree.put(s.charAt(i), 0);
        }

        for (int i = 0; i < words.length-1; i++) {
                String s1 = words[i], s2 = words[i+1];
                if (s1.length() > s2.length() && s1.startsWith(s2))
                    return "";
                int len = Math.min(s1.length(), s2.length());
                for (int idx = 0; idx < len; idx++) {
                    char c1 = s1.charAt(idx), c2 = s2.charAt(idx);
                    if (c1 != c2){
                        Set<Character> st;
                        if (mp.containsKey(c1))
                            st = mp.get(c1);
                        else
                            st = new HashSet<>();
                        if (!st.contains(c2)) {
                            st.add(c2);
                            mp.put(c1, st);
                            indegree.put(c2, indegree.get(c2) + 1);
                        }
                        break;
                    }
                }

        }

        StringBuilder sb = new StringBuilder();
        Queue<Character> q = new LinkedList<>();
        for (Character key: indegree.keySet()) {
            if (indegree.get(key) == 0) {
                q.offer(key);
            }
        }

        Set<Character> vis = new HashSet<>();
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Character ch = q.poll();

                if (vis.contains(ch))
                    continue;
                vis.add(ch);
                if (indegree.get(ch) == 0)
                    sb.append(ch);

                if (mp.containsKey(ch)) {
                    for (Character c : mp.get(ch)) {
                        indegree.put(c, indegree.get(c) - 1);
                        if (indegree.get(c) == 0)
                            q.offer(c);
                    }
                }
            }
        }

        return sb.length() != indegree.size()?"":sb.toString();
    }
