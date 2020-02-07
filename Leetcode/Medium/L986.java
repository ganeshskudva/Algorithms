class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
    List<int[]> list = new ArrayList<>();
    for(int i=0, j=0; i < A.length && j < B.length; ) {
        if(A[i][1] < B[j][0]) i++;
        else if(B[j][1] < A[i][0]) j++;
        else {
            int start = Math.max(A[i][0], B[j][0]);
            int end = Math.min(A[i][1], B[j][1]);
            list.add(new int[]{start, end});
            
            if(A[i][1] < B[j][1]) i++;
            else j++;
        }
    }
    return list.toArray(new int[0][]);
    }
}
