class Solution {
public String getHappyString(int n, int k) {
        List<String> res = new ArrayList<>();
        char[] arr = {'a', 'b', 'c'};
        dfs(res, new StringBuilder(), arr, n, k);
        
        
        return res.size() == k ? res.get(res.size() - 1): "";
    }
    
    private void dfs(List<String> res, StringBuilder sb, char[] arr, int n, int k) {
        if (res.size() == k)
            return;
        if (sb.length() == n) {
            res.add(sb.toString());
            return;
        }
        
        for (int i = 0; i < 3 ; i++) {
            if (sb.length() == 0 || sb.charAt(sb.length() - 1) != arr[i]) {
                sb.append(arr[i]);
                dfs(res, sb, arr, n, k);
                sb.deleteCharAt(sb.length() - 1);
            }
        }
    }
}
