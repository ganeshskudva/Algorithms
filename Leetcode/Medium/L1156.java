// 1156. Swap For Longest Repeated Character Substring
public int maxRepOpt1(String s) {
        int[] freq = new int[26];
        char[] ch = s.toCharArray();
        for(int i=0; i < ch.length; i++)
            freq[ch[i]-'a']++;
        int max = 0;
        for(int i=0; i < ch.length; i++){
            char curr = ch[i];
            int j=i, count = 0, diff = 0;
            while(j < ch.length && (curr == ch[j] || diff == 0) && count < freq[curr-'a']){
                if(curr != ch[j]) 
                	++diff;
                ++count;
                ++j;
            }
            max = Math.max(max, count);
        }
        return max;
    }
