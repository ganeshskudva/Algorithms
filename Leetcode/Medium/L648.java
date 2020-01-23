class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        String[] arr = sentence.split(" ");
        int i = 0;
        
        for (i = 0; i < arr.length; i++) {
            for (String str : dict) {
                if (arr[i].startsWith(str))
                    arr[i] = str;
            }
        }
        
        StringBuffer sb = new StringBuffer();
        for (i = 0; i < arr.length;  i++) {
            sb.append(arr[i]);
            if (i != arr.length-1)
                sb.append(" ");
        }
        
        return sb.toString();
    }
}
