class Solution {
    public List<String> generatePalindromes(String s) {
        List<String> res = new ArrayList<>();
        int odd = 0;
        String mid = "";
        int []hash = new int[256];
        int length = 0; 
        for(int i=0; i<s.length(); i++){
            hash[s.charAt(i)]++;
        }

        for(int i=0; i<256; i++){
            if(hash[i] > 0){
                if(hash[i] % 2 != 0){
                    odd++;
                    if (odd > 1) return new LinkedList<String>();
                    mid = String.valueOf((char)i);
                    hash[i]--;
                }
                hash[i] /= 2;
                length += hash[i];
            }
        }
        
        backtrack(res, hash, new StringBuffer(), mid, length);
        return res;
    }
    
    void backtrack(List<String> res, int[] hash, StringBuffer sb, String mid, int length){
        if (sb.length() == length){
            res.add(sb.toString() + mid + sb.reverse().toString());
            sb.reverse();
            return;
        }
        
        for(int i=0; i<256; i++){
            if(hash[i] > 0){
                hash[i]--;
                sb.append((char)i);
                backtrack(res, hash, sb, mid, length);
                sb.deleteCharAt(sb.length() -1);
                hash[i]++;
            }
        }
        
    }
}
