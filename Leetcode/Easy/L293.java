class Solution {
public List<String> generatePossibleNextMoves(String s) {
        List<String> answer = new ArrayList<>();
        char[] arr = s.toCharArray();
        for(int i = 0; i < arr.length - 1; i++){
            if(arr[i] == '+' && arr[i+1] == '+'){
                arr[i] = '-'; arr[i+1] = '-';
                answer.add(new String(arr));
                arr[i] = '+'; arr[i+1] = '+';
            }
        }
        return answer;
    }
}
