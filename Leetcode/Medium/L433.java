// 433. Minimum Genetic Mutation
class Solution {
public int minMutation(String beginWord, String endWord, String[] bank) {
        List<String> wordList = new ArrayList<>(Arrays.asList(bank));
        Set<String> beginSet = new HashSet<String>(), endSet = new HashSet<String>();
        boolean exists = false;

        for (String str: wordList) {
            if (str.equals(endWord))
                exists = true;
        }

        if (!exists)
            return -1;

        int len = 0;
        int strLen = beginWord.length();
        HashSet<String> visited = new HashSet<String>();

        beginSet.add(beginWord);
        endSet.add(endWord);
        while (!beginSet.isEmpty() && !endSet.isEmpty()) {
            if (beginSet.size() > endSet.size()) {
                Set<String> set = beginSet;
                beginSet = endSet;
                endSet = set;
            }

            Set<String> temp = new HashSet<String>();
            for (String word : beginSet) {
                char[] chs = word.toCharArray();

                for (int i = 0; i < chs.length; i++) {
                    for (char c = 'A'; c <= 'Z'; c++) {
                        char old = chs[i];
                        chs[i] = c;
                        String target = String.valueOf(chs);

                        if (endSet.contains(target)) {
                            return len + 1;
                        }

                        if (!visited.contains(target) && wordList.contains(target)) {
                            temp.add(target);
                            visited.add(target);
                        }
                        chs[i] = old;
                    }
                }
            }

            beginSet = temp;
            len++;
        }

        return -1;
    }
}
